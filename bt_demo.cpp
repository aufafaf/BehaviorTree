#include <iostream>
#include <chrono>
#include "behaviortree_cpp_v3/action_node.h"
#include "behaviortree_cpp_v3/bt_factory.h"

using namespace std::chrono_literals;

BT::NodeStatus ballFound()
{
    std::cout << "Ball not found" << std::endl;
    return BT::NodeStatus::FAILURE;
}

class FindBall : public BT::SyncActionNode
{
    public:
        explicit FindBall(const std::string& name) : BT::SyncActionNode(name, {})
        {

        }

        BT::NodeStatus tick() override
        {
            std::this_thread::sleep_for(3s);
            std::cout << "Ball Found" << std::endl;
            return BT::NodeStatus::SUCCESS;
        }
};

BT::NodeStatus ballClose()
{
    std::cout << "Ball not close" << std::endl;
    return BT::NodeStatus::FAILURE;
}

class ApproachBall : public BT::SyncActionNode
{
    public:
        explicit ApproachBall(const std::string& name) : BT::SyncActionNode(name, {})
        {

        }

        BT::NodeStatus tick() override
        {
            std::this_thread::sleep_for(3s);
            std::cout << "Ball Approached" << std::endl;
            return BT::NodeStatus::SUCCESS;
        }
};

BT::NodeStatus ballKicked()
{
    std::cout << "Ball not kicked" << std::endl;
    return BT::NodeStatus::FAILURE;
}

class KickBall : public BT::SyncActionNode
{
    public:
        explicit KickBall(const std::string& name) : BT::SyncActionNode(name, {})
        {

        }

        BT::NodeStatus tick() override
        {
            std::this_thread::sleep_for(3s);
            std::cout << "Ball Kicked" << std::endl;
            return BT::NodeStatus::SUCCESS;
        }
};

int main(){
    BT::BehaviorTreeFactory factory;

    factory.registerSimpleCondition("BallFound", std::bind(ballFound));
    factory.registerNodeType<FindBall>("FindBall");

    factory.registerSimpleCondition("BallClose", std::bind(ballClose));
    factory.registerNodeType<ApproachBall>("ApproachBall");

    factory.registerSimpleCondition("BallKicked", std::bind(ballKicked));
    factory.registerNodeType<KickBall>("KickBall");

    auto tree = factory.createTreeFromFile("./../bt_tree.xml");
    tree.tickRoot();
    
    return 0;
}