# MiniRedis

🧠 A minimal Redis clone written in C++ for learning purposes.

## Features

- SET key value
- GET key
- DEL key
- Simple REPL (Read-Eval-Print Loop)

## Build

```bash
g++ -std=c++17 -o miniredis main.cpp redis.cpp
./miniredis
```
 
## Example

```bash
redis> SET name shawon
redis> GET name
shawon
redis> DEL name
OK
```

## Roadmap

- [x] Basic key-value store
- [ ] TTL support
- [ ] RESP protocol + TCP networking
- [ ] AOF persistence
- [ ] Pub/Sub


