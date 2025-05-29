// 2025-5-29
// BM85 验证IP地址 <Medium> [字符串]

#include "environment.h"

using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 验证IP地址
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串
     */
    string solve(string IP) {
        // write code here
        auto pos1 = IP.find('.'), pos2 = IP.find(':');
        if (pos1 == string::npos && pos2 == string::npos) return "Neither";
        if (pos1 != string::npos) { // 验证IPv4
            IP.push_back('.'); // 补一个'.'方便分割
            for (int i = 0; i < 4; ++i) {
                auto pos = IP.find('.');
                if (pos == string::npos) return "Neither";
                string part = IP.substr(0, pos);
                IP = IP.substr(pos + 1); // 按'.'分割

                // 验证地址的每一段
                if (part.empty()) return "Neither"; // 不能为空
                for (char c : part) {
                    if (!isdigit(c)) return "Neither";
                } // 必须全部是数字
                int value = stoi(part);
                if (value >= 0 && value <= 255) { // 转换值在0~255间
                    if (value != 0 && part[0] == '0' || value == 0 && part.size() > 1) return "Neither";
                    // 不能有多余的0
                } else return "Neither";
            }
            if (!IP.empty()) return "Neither"; // IP不能有多余内容
            return "IPv4";
        } else if (pos2 != string::npos) { // 验证IPv6
            IP.push_back(':'); // 补一个':'方便分割
            for (int i = 0; i < 8; ++i) {
                auto pos = IP.find(':');
                if (pos == string::npos) return "Neither";
                string part = IP.substr(0, pos);
                IP = IP.substr(pos + 1); // 分割

                if (part == "0") continue; // 可以是单个0
                if (part.size() != 4) return "Neither"; //必须是4位
                for (char c : part) {
                    if (!isxdigit(c)) return "Neither";
                    // 必须是16进制数 0~9 a~f A~F
                }
            }
            if (!IP.empty()) return "Neither"; // IP不能有多余内容
            return "IPv6";
        } 
        return "Neither";
    }
};