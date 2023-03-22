//
// Created by igor on 03.01.23.
//

#ifndef CPP_YANDEX_COURSE_TASKMANAGER_H
#define CPP_YANDEX_COURSE_TASKMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <tuple>

enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};


using std::map; using std::vector;
using std::string;
using std::tuple;
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {

        return team_db_.at(person);

    };

    void AddNewTask(const string& person) {
        ++team_db_[person][TaskStatus::NEW];

    };

    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int perform_task_count) {
        TasksInfo updated_tasks, untouched_tasks;

        if (! team_db_.count(person)) {
            return std::tie(updated_tasks,untouched_tasks);
        }

        for (auto & [task_status, task_count] : team_db_.at(person)) {
            auto current_task_status_code = static_cast<int>(task_status);
            auto next_task_status = static_cast<TaskStatus> (current_task_status_code + 1);

            while (task_count > 0 && perform_task_count > 0 && task_status != TaskStatus::DONE) {
                    ++updated_tasks[next_task_status];
                    --perform_task_count;
                    --task_count;
            }
            if (task_count > 0 && task_status != TaskStatus::DONE){
                untouched_tasks[task_status] = task_count;
            }
        }

        for (auto & [task_status, task_count] : untouched_tasks){
            team_db_[person][task_status] = task_count;
        }
        for (auto & [task_status, task_count] : updated_tasks){
            team_db_[person][task_status] += task_count;
        }

        return tie(updated_tasks, untouched_tasks);

    }



    map<string, TasksInfo> team_db_;

};


#endif //CPP_YANDEX_COURSE_TASKMANAGER_H
