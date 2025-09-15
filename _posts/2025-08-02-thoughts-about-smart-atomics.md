---
title: My thoughts on Smart Atomics
published: true
permalink: "/thoughts-about-smart-atomics"
tags: [atomics]
readtime: true
comments: false
---


So we will be implementing a  shared lock (Dont confuse this with std::shared_mutex, then concept is similar but design is different).
This lock will give RAII lock management with upgrade/downgrade features by using std::mutex instead of std::shared_mutex.
So the logic of shared/exclusive will be managed manually in the lock instead of in the mutex as in std::shared_mutex.

wip