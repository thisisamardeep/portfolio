---
title: How to enable in-band FEC for Opus codec
published: true
permalink: "/how-to-enable-in-band-fec-for-opus-codec/"
share-img: /img/How-to-Test-Packet-Loss-on-Windows.png
share-description: "Minimal steps to enable in-band FEC for OPUS codec"
tags: [udp, opus, fec, rtcp, rtp]
readtime: true
comments: false
---

As a reader may know UDP network protocol does not support either message retransmission or acknowledgment.  It means that
all these problems are supposed to be handled at the application level.  In the audio/video transmission domain, the problem
is usually solved with the [forward error correction](https://en.wikipedia.org/wiki/Forward_error_correction){:target="_blank"} technique.
The idea is to add some redundant data to a message so that if one of the messages is lost, a receiver could
replicate it from a combination of other messages and redundant data. This redundant data is called FEC.

![Packet loss image](/img/How-to-Test-Packet-Loss-on-Windows.png)

A developer is supposed to decide how much FEC to add to the messages on the encoder side and how to decode it on the decoder side. It sounds like a piece of work!
So Opus codec developers decided to make our life easier and added in-band FEC support to the codec.

In order to make the OPUS encoder add FEC a user has to set the following configuration:

* Packet time(`ptime`) has to be not less than 10ms otherwise OPUS works in the
[CELT](https://en.wikipedia.org/wiki/CELT){:target="_blank"} mode and not in [SILK](https://en.wikipedia.org/wiki/SILK){:target="_blank"}.
* Don't use very high bitrates. For example, I use 24 kbps.
* In order to use FEC, your bitrate should be higher. For example,
if the sample rate is 8kHz then the bitrate has to be 12 kbps or 24 kbps.
The encoder needs a higher bitrate to have room for LBRR packets containing FEC.
* FEC must be enabled via `OPUS_SET_INBAND_FEC`.
* The encoder must be told to expect packet loss via `OPUS_SET_PACKET_LOSS_PERC`.

Here is an example of configuring the OPUS encoder.

```c
opus_encoder_ctl(encoder, OPUS_SET_INBAND_FEC(TRUE));
opus_encoder_ctl(encoder,OPUS_SET_PACKET_LOSS_PERC(opus_packet_loss));
```

I configure `opus_packet_loss` via config file but it may be configured in realtime.
For example, you can update OPUS according to [RTCP](https://en.wikipedia.org/wiki/RTP_Control_Protocol){:target="_blank"}
statistics.

Now, after the encoder is ready, let's configure the decoder.
First of all, you need to know if a packet is lost.
The most natural way to know it is to check the sequence number of RTP packets.
When you know that the previous packet is lost you are supposed to decode the current packet twice:
first time with FEC turned on to reproduce the lost packet, and then with FEC turned off to decode the current packet.

```c
/* Decode the lost packet */
opus_decoder_ctl(decoder, OPUS_GET_LAST_PACKET_DURATION(frame_size));
opus_decode(decoder,
            buffer, /* buffer to decode */,
            length, /* number of bytes in buffer */
            sampv,  /* output buffer */
            frame_size,
            1);     /* in-band FEC is turned on */
play_buffer(buffer);
/*Decode the current packet*/
opus_decode(decoder,
            buffer, /* buffer to decode */,
            length, /* number of bytes in buffer */
            sampv,  /* output buffer */
            frame_size,
            0);     /* in-band FEC is turned off */
play_buffer(buffer);
```

## Summary ##

We learned how to enable in-band FEC for Opus codec but the last thing to talk about is the pros and cons of using it!

### Pros ###

* No need to develop an in-house mechanism for adding FEC to your packets.
* Most of the third parties like SIP servers(Asterisk) or WebRTC support Opus in-band FEC out of the box.
* FEC may increase the audio quality even when there is a packet loss.

### Cons ###

* Tricky to configure.
* There is no obvious way to see if traffic actually carries in-band FEC except by generating packet loss and listening to
an audio sample. I used a sine wave generated by:

    ```plain
    ffmpeg -f lavfi -i
    "sine=frequency=1000:sample_rate=8000:duration=5" output.wav
    ```

* Since the Opus packet contains information only about the prior packet in-band FEC can replicate only a single packet
loss.  The problem is that usually packets are lost in a burst.
* Enabling FEC increases bitrate and bandwidth.