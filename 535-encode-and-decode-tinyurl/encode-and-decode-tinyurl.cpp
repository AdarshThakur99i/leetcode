class Solution {
    private:
     unordered_map<string,string> shortTolong;
     unordered_map<string,string> longToShort;
     int cnt=0;
     string base="http://tinyurl.com/";
public:
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
               string shortUrl= base+to_string(cnt++);
               shortTolong[shortUrl]=longUrl;
            longToShort[longUrl]=shortUrl;
            return shortUrl;
                }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortTolong[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));