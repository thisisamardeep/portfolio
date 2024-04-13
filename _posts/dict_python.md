---
title: dict in python
published: true
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/dict-in-python"
share-description: "dict in python"
comments: false
---

Python dict check if keys exists.

```python
d = {"key1": 10, "key2": 23}

if "key1" in d:
    print("this will execute")

if "nonexistent key" in d:
    print("this will not")

```