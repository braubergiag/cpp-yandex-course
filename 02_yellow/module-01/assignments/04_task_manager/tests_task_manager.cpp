#include <gtest/gtest.h>
#include "TaskManager.h"


TEST(TaskManger,AddTask){
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }

    ASSERT_EQ(tasks.GetPersonTasksInfo("Ilia").at(TaskStatus::NEW),1);
    ASSERT_EQ(tasks.GetPersonTasksInfo("Ivan").at(TaskStatus::NEW),3 );

}

TEST(TaskManager,PerformTasks_1){
    TeamTasks tasks;
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    auto [updated,untouched] = tasks.PerformPersonTasks("Ivan",3);

    ASSERT_EQ(tasks.GetPersonTasksInfo("Ivan").at(TaskStatus::NEW),0 );
    ASSERT_EQ(tasks.GetPersonTasksInfo("Ivan").at(TaskStatus::IN_PROGRESS),3 );

    ASSERT_EQ(updated.at(TaskStatus::IN_PROGRESS),3);

}

TEST(TaskManager,PerformTasks_2){
    TeamTasks tasks;
    tasks.team_db_["Igor"][TaskStatus::NEW] = 3;
    tasks.team_db_["Igor"][TaskStatus::IN_PROGRESS] = 2;
    tasks.team_db_["Igor"][TaskStatus::TESTING] = 4;
    tasks.team_db_["Igor"][TaskStatus::DONE] = 1;

    auto [updated,untouched] = tasks.PerformPersonTasks("Igor",4);


    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::NEW],0);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::IN_PROGRESS],4);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::TESTING],5);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::DONE],1);

    ASSERT_EQ(updated.at(TaskStatus::IN_PROGRESS), 3);
    ASSERT_EQ(updated.at(TaskStatus::TESTING), 1);
    ASSERT_EQ(updated.size(),2);

    ASSERT_EQ(untouched.at(TaskStatus::IN_PROGRESS),1);
    ASSERT_EQ(untouched.at(TaskStatus::TESTING),4);
    ASSERT_EQ(untouched.size(),2);


}
TEST(TaskManager,PerformTasks_3) {

    TeamTasks tasks;
    tasks.team_db_["Igor"][TaskStatus::NEW] = 0;
    tasks.team_db_["Igor"][TaskStatus::IN_PROGRESS] = 2;
    tasks.team_db_["Igor"][TaskStatus::TESTING] = 4;
    tasks.team_db_["Igor"][TaskStatus::DONE] = 1;

    auto [updated,untouched] = tasks.PerformPersonTasks("Igor",6);

    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::NEW],0);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::IN_PROGRESS],0);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::TESTING],2);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::DONE],5);

    ASSERT_EQ(updated.at(TaskStatus::TESTING), 2);
    ASSERT_EQ(updated.at(TaskStatus::DONE), 4);
    ASSERT_EQ(updated.size(),2);

    ASSERT_EQ(untouched.size(),0);


}

TEST(TaskManager,PerformTasks_4) {

    TeamTasks tasks;
    tasks.team_db_["Igor"][TaskStatus::NEW] = 2;
    tasks.team_db_["Igor"][TaskStatus::IN_PROGRESS] = 0;
    tasks.team_db_["Igor"][TaskStatus::TESTING] = 0;
    tasks.team_db_["Igor"][TaskStatus::DONE] = 0;

    auto [updated,untouched] = tasks.PerformPersonTasks("Igor",4);

    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::NEW],0);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::IN_PROGRESS],2);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::TESTING],0);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::DONE],0);

    ASSERT_EQ(updated.at(TaskStatus::IN_PROGRESS), 2);
    ASSERT_EQ(updated.size(),1);

    ASSERT_EQ(untouched.size(),0);
}

TEST(TaskManager,PerformTasks_5) {
    TeamTasks tasks;
    tasks.team_db_["Igor"][TaskStatus::NEW] = 2;
    tasks.team_db_["Igor"][TaskStatus::IN_PROGRESS] = 2;
    tasks.team_db_["Igor"][TaskStatus::TESTING] = 2;
    tasks.team_db_["Igor"][TaskStatus::DONE] = 0;

    auto [updated,untouched] = tasks.PerformPersonTasks("Igor",6);

    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::NEW],0);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::IN_PROGRESS],2);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::TESTING],2);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::DONE],2);

    ASSERT_EQ(updated.at(TaskStatus::IN_PROGRESS), 2);
    ASSERT_EQ(updated.at(TaskStatus::TESTING), 2);
    ASSERT_EQ(updated.at(TaskStatus::DONE), 2);
    ASSERT_EQ(updated.size(),3);

    ASSERT_EQ(untouched.size(),0);

}

TEST(TaskManager,PerformTasks_6) {
    TeamTasks tasks;
    tasks.team_db_["Igor"][TaskStatus::NEW] = 0;
    tasks.team_db_["Igor"][TaskStatus::IN_PROGRESS] = 0;
    tasks.team_db_["Igor"][TaskStatus::TESTING] = 0;
    tasks.team_db_["Igor"][TaskStatus::DONE] = 4;



    auto [updated,untouched] = tasks.PerformPersonTasks("Igor",6);

    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::DONE],4);

    ASSERT_EQ(updated.size(),0);
    ASSERT_EQ(untouched.size(),0);



}
TEST(TaskManager,PerformTasks_7) {

    TeamTasks tasks;
    tasks.team_db_["Igor"][TaskStatus::NEW] = 0;
    tasks.team_db_["Igor"][TaskStatus::IN_PROGRESS] = 0;
    tasks.team_db_["Igor"][TaskStatus::TESTING] = 4;
    tasks.team_db_["Igor"][TaskStatus::DONE] = 0;

    auto [updated,untouched] = tasks.PerformPersonTasks("Igor",6);

    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::TESTING],0);
    ASSERT_EQ(tasks.team_db_.at("Igor")[TaskStatus::DONE],4);

    ASSERT_EQ(updated.at(TaskStatus::DONE), 4);
    ASSERT_EQ(updated.size(),1);

    ASSERT_EQ(untouched.size(),0);


}
