import java.util.*;

class MyCalendarTwo {
    private List<int[]> events;
    private List<int[]> doubles;

    public MyCalendarTwo() {
        events = new ArrayList<>();
        doubles = new ArrayList<>();
    }

    public boolean book(int start, int end) {
        for (int[] event : doubles) {
            if (event[0] < end && start < event[1]) {
                return false;
            }
        }
        for (int[] event : events) {
            if (event[0] < end && start < event[1]) {
                doubles.add(new int[]{Math.max(start, event[0]), Math.min(end, event[1])});
            }
        }
        events.add(new int[]{start, end});
        return true;
    }
}