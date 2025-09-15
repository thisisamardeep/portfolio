---
title: My thoughts on kernel bypass and 1000k per second packet problem
published: true
permalink: "/thoughts-about-kernel-bypass"
tags: [bypass,kernel]
readtime: true
comments: false
---

Kernel bypass is one of toughest things to get right.The benefits if you get it right are huge and cost if 
you get it wrong are also huge.So it becomes a double edged sword .It can be a deal breaker between alpha on book or
loss on book.

This project aims to integrate asio with kernel bypass.The aim of the project using iouring we should be able to target
1000k packets per second .This is just a start project code is [here](https://github.com/thisisamardeep/kernel-udp-tcp).
More to follow later.