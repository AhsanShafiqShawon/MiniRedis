#ifndef REDIS_H
#define REDIS_H

#include <string>
#include <unordered_map>

class Redis {
public:
	void set(const std::string& key, const std::string& value);
	std::string get(const std::string& key) const;
	bool del(const std::string& key);
private:
	std::unordered_map<std::string, std::string> store_;
};

#endif
