---
title: maps in java
published: true
tags: [ leetcode ]
share-img: /img/rust.png
readtime: true
permalink: "/maps-in-java"
share-description: "maps in java"
comments: false
---

Map is interface.

3 important map types in java.

HashMap

LinkedHashMap

TreeMap

Default is HashMap

```java
import java.util.HashMap; // import the HashMap class
HashMap<String, String> capitalCities = new HashMap<String, String>();
```

Adding Elements in HashMap in Java

```java
import java.util.HashMap; // import the HashMap class
HashMap<String, String> capitalCities = new HashMap<String, String>();
capitalCities.put("1", "Geeks");

```

Finding if a key exists or not in java

```java
 HashMap<String, String> capitalCities = new HashMap<String, String>();
        capitalCities.put("1", "Geeks");
        boolean res = capitalCities.containsKey("4");

```