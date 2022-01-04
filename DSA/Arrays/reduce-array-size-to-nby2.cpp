class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        
        for(int i=0; i<n; i++)
            freq[arr[i]]++;
        
        vector<int> sortedFreq;
        
        for(auto it=freq.begin(); it!= freq.end(); it++) {
            sortedFreq.push_back(it->second);
        }
        
        sort(sortedFreq.rbegin(), sortedFreq.rend());
        
        int sum = 0, i = 0; 
        while(i < n && sum < n/2) {
            sum += sortedFreq[i++];
        }
        
        return i;
    }
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>mp;
        multiset<int, greater<int>> s;
		for(auto num : arr) mp[num]++;                  // find frequency of elements
        for(auto [num, freq] : mp) s.insert(freq);      // sort frequency in descending order
        for(int deleted{}, ans{}; auto freq : s) {      // keep deleting till array size is reduced to half
            deleted += freq, ans++;
            if(deleted >= size(arr) / 2) return ans;    // atleast half array is deleted
        }
        return -1;  // won't ever be reached
    }
};

class Solution {
    static const int MAX = 100000;
public:
    int minSetSize(vector<int>& arr) {        
        int freq[MAX+1]{}, freqBuckets[MAX+1]{}, ans = 0;
        for(auto num : arr) freq[num]++;                     // get frequency of elements
        for(int i = 0; i < MAX; i++) freqBuckets[freq[i]]++; // get instances of each frequency
        for(int i = MAX, deleteRequired = size(arr) / 2; deleteRequired > 0; i--) {
            if(!freqBuckets[i]) continue;                    // no elements having this frequency
            int noOfFreqToDelete = min(freqBuckets[i], max(1, deleteRequired / i));   // above-mentioned optimization
            deleteRequired -= i * noOfFreqToDelete;          // delete elements having frequency = i
            ans += noOfFreqToDelete;                         // increment by number of instances of frequency (unique elements) deleted
        }   
        return ans;
    }
};