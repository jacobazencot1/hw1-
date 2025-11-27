//
// Created by yonat on 27/11/2025.
//

#ifndef MYPROJECT_NODESTDINCOURSE_H
#define MYPROJECT_NODESTDINCOURSE_H


class NodeStdsInCourse {

    public:
        NodeStdsInCourse(int id);
        int getId() const;
        int getPoints() const;
        NodeStdsInCourse* fatherPtr;
        NodeStdsInCourse* lSon;
        NodeStdsInCourse* rSon;
        int insert (NodeStdsInCourse* std);
        int remove (NodeStdsInCourse* std);





    private:
        int id;
        int points;
    };
};


#endif //MYPROJECT_NODESTDINCOURSE_H
