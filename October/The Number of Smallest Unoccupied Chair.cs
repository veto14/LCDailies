using System;
using System.Collections.Generic;

public class Solution {
    public int SmallestChair(int[][] times, int targetFriend) {
        int n = times.Length;
        // List to store (arrival, friend index)
        List<(int, int)> arrivals = new List<(int, int)>();
        // Priority queue to store the smallest available chairs
        SortedSet<int> availableChairs = new SortedSet<int>();
        // List to store leaving times with their associated chairs
        List<(int, int)> leavingTimes = new List<(int, int)>();

        // Fill arrival and leaving lists
        for (int i = 0; i < n; i++) {
            arrivals.Add((times[i][0], i));
            leavingTimes.Add((times[i][1], i));
        }

        // Sort by arrival time
        arrivals.Sort((a, b) => a.Item1.CompareTo(b.Item1));
        // Sort by leaving time
        leavingTimes.Sort((a, b) => a.Item1.CompareTo(b.Item1));

        int currentTime = 0, chairCount = 0;
        int leaveIdx = 0;

        // Dictionary to store the chair assigned to each friend
        Dictionary<int, int> assignedChairs = new Dictionary<int, int>();

        foreach (var arrival in arrivals) {
            int friend = arrival.Item2;
            currentTime = arrival.Item1;

            // Free up chairs based on current time
            while (leaveIdx < n && leavingTimes[leaveIdx].Item1 <= currentTime) {
                int leavingFriend = leavingTimes[leaveIdx].Item2;
                availableChairs.Add(assignedChairs[leavingFriend]);
                leaveIdx++;
            }

            // Assign the smallest available chair
            int chair;
            if (availableChairs.Count > 0) {
                chair = availableChairs.Min;
                availableChairs.Remove(chair);
            } else {
                chair = chairCount;
                chairCount++;
            }

            // Assign the chair to the friend
            assignedChairs[friend] = chair;

            // If it's the target friend, return their chair number
            if (friend == targetFriend) {
                return chair;
            }
        }

        return -1;  // This case should never be reached
    }
}