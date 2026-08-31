
class TimeMap {
public:

    struct Node {
        string value;
        int timestamp;

        Node(string v, int t) {
            value = v;
            timestamp = t;
        }
    };

    unordered_map<string, vector<Node>> mp;

    TimeMap() {
        
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back(Node(value, timestamp));
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        vector<Node>& arr = mp[key];

        int low = 0;
        int high = arr.size() - 1;

        string ans = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid].timestamp <= timestamp) {
                ans = arr[mid].value;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */