class Logger {
    unordered_map<string, int> times;
public:
    Logger() : times() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (times.find(message) == times.end() ||
            times[message] + 10 <= timestamp) {
            times[message] = timestamp;
            return true;
        } else return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

