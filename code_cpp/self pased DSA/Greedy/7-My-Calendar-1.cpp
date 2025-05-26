/*Problem
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.

*************

Approach:
The big idea is pretty simple:
Each time of book, instead of fail a book when there is 1 or more overlap with existing books as in MyCalendar I, we just want to make sure these overlaps does not overlap - having overlap is now ok, but overlapped period cannot be overlapped again.
So we just need to keep track of all the overlaps with any previous books

*/

class MyCalendar {
public:
    vector<pair<int, int>> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto p: cal)
        {
            int s1 = p.first;
            int e1 = p.second;
            int maxStartTime = max(s1, start);
            int MinEndTime = min(e1, end);
            // check if we can add event into the calander 
            if(maxStartTime < MinEndTime)
                return false;
        }
        cal.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */