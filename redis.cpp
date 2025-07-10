#include "redis.h"

void Redis::set(const std::string& key, const std::string& value) {
	store_[key] = value;
}

std::string Redis::get(const std::string& key) const {
	auto it = store_.find(key);
	return it != store_.end() ? it -> second : "(nil)";
}

bool Redis::del(const std::string& key) {
	return store_.erase(key) > 0;
}
