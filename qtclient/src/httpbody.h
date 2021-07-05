
#ifndef	 HTTPBODY_H
#define	 HTTPBODY_H
 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdint.h>
#include "json.h"

using json = nlohmann::json;

namespace resp {
	struct respresult {
		std::string result;
		int status;
	};
	void to_json(json& j, const respresult& ver) {
		j = json{{"result", ver.result},
				 {"status", ver.status}};
	}

	void from_json(const json& j, respresult& ver) {
		ver.result = j.at("result").get<std::string>();
		ver.status = j.at("status").get<int>();
	}
} 
#endif  // HTTPBODY_H