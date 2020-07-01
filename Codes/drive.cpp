#include <iostream>

#define L1 5
#define L2 6
#define R1 10
#define R2 11

void Drive() {
}

void backwardMovement() {
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW); 
}

void forwardMovement() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH); 
}

void moveRight() {
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH); 
}

void moveLeft() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW); 
}

void stopMotor() {
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW); 
}

int main(){
    vector<int> robot_position = robot.getPosition();

    bool checkRescueRobot() {
        if(driveAbleOnWature)
            Return True;
        else return False;
    }

    if (checkRescue == True) {
        std::vector<RouteModel::Node> obstacle;
        obstacle.emplace_back("Water");
    }

    float next_path = Astar().path;

    Drive();
}



