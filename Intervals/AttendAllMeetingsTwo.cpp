#include <vector>
#include <algorithm>
#include <optional>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};


class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<bool> inserted(intervals.size(), false);
        sort(intervals.begin(), intervals.end(), [](Interval one, Interval two) {
            one.start < two.start;
        });

        int number_delt_with = 0;
        int count = 0;

        while(number_delt_with != intervals.size()) {
            Interval one{0,0};
            bool has_interval = false;
            int i=0;
            for(i;i<intervals.size(); i++) {
                if(inserted[i]) continue;
                if(has_interval) {
                    if(overlaps(one, intervals[i])) {
                        if(one.end < intervals[i].end) {
                            continue;
                        } else {
                            one = intervals[i];
                        }
                    } else {
                        one = intervals[i];
                        inserted[i] = true;
                        number_delt_with--;
                    }
                } else {
                    one = intervals[i];
                    has_interval = true;
                }
            }
            if(has_interval) {
                number_delt_with--;
                inserted[i - 1] = true;
            }
            count += 1;
        }

        return count;
    }

    bool overlaps(Interval one, Interval two) {
        if(one.end > two.start) {
            return true;
        }
    }


};
