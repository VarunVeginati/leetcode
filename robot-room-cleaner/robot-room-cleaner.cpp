/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    map<pair<int,int>,int> visited;
    
    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }
    
    vector<pair<int,int> > directions = {
        make_pair(-1,0),
        make_pair(0,1),
        make_pair(1,0),
        make_pair(0,-1)
    };
    
    void back_track(Robot& robot, int row, int col, int d) {
        robot.clean();
        visited[make_pair(row, col)]++;
        
        for(int i=0; i<4; i++) {
            int newD = (d+i)%4;
            int r = row+directions[newD].first;
            int c = col+directions[newD].second;
            
            if(visited[make_pair(r,c)]<=0 && robot.move()) {
                back_track(robot, r, c, newD);
                goBack(robot);
            }
            robot.turnRight();
        }
    }
    
    void cleanRoom(Robot& robot) {
        back_track(robot, 0, 0, 0);
    }
};