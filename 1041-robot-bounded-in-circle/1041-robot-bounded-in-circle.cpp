class Solution {
public:
    bool isRobotBounded(string instructions) {
        int direction = 1;
        int i=0;
        // map<pair<int,int>, int> m;
        pair<int,int> position = make_pair(0,0);
        int n = instructions.length();
        
        while(i<(n*10)) {
            if(instructions[i%n] == 'G') {
                switch(direction) {
                    case 1:
                        position = make_pair(position.first, position.second+1);
                        break;
                    case 2:
                        position = make_pair(position.first, position.second-1);
                        break;
                    case 3:
                        position = make_pair(position.first+1, position.second);
                        break;
                    case 4:
                        position = make_pair(position.first-1, position.second);
                        break;
                }
            } else if(instructions[i%n] == 'L') {
                switch(direction) {
                    case 1:
                        direction = 3;
                        break;
                    case 2:
                        direction = 4;
                        break;
                    case 3:
                        direction = 2;
                        break;
                    case 4:
                        direction = 1;
                        break;
                }
            } else {
                switch(direction) {
                    case 1:
                        direction = 4;
                        break;
                    case 2:
                        direction = 3;
                        break;
                    case 3:
                        direction = 1;
                        break;
                    case 4:
                        direction = 2;
                        break;
                }
            }
            
            i++;
            
            if(position == make_pair(0,0)) {
                if(direction==1 && i%n==0)
                    return true;
            }
        }
        
        return false;
    }
};