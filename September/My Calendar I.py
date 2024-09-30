import bisect

class MyCalendar:
    def __init__(self):
        self.calendar = []
    
    def book(self, start: int, end: int) -> bool:
        i = bisect.bisect_right(self.calendar, (start, end))
        
        if i > 0 and self.calendar[i-1][1] > start:
            return False
        
        if i < len(self.calendar) and self.calendar[i][0] < end:
            return False
        
        self.calendar.insert(i, (start, end))
        return True