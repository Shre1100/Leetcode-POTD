// You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:
// (startx, starty): The bottom-left corner of the rectangle.
// (endx, endy): The top-right corner of the rectangle.
// Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:
// Each of the three resulting sections formed by the cuts contains at least one rectangle.
// Every rectangle belongs to exactly one section.
// Return true if such cuts can be made; otherwise, return false.

class Solution {
private:
    bool canCut(vector<vector<int>>& rectangles, int axis) {
        sort(rectangles.begin(), rectangles.end(),
             [axis](vector<int>& a, vector<int>& b) { return a[axis] < b[axis]; });

        int cuts = 0, previousEnd = -1;

        for (auto& rect : rectangles) {
            int start = rect[axis], end = rect[axis + 2];

            if (start >= previousEnd) cuts++;
            previousEnd = max(previousEnd, end);
            if (cuts >= 3) return true;
        }

        return false;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return canCut(rectangles, 0) || canCut(rectangles, 1);
    }
};
