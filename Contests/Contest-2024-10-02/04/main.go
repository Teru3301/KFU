package main

import (
	"fmt"
	"io/ioutil"
	"encoding/json"
)


type Task struct {
	User_id		int
	Task_id 	int
	Title		string
	Completed	bool
}

type Project struct {
	Project_id	int
	Tasks		[]Task
}


func main () {
	completed_tasks := 0
	user_id := 0

	fmt.Scan(&user_id)

	file, _ := ioutil.ReadFile("data.json")
	var projects []Project
	json.Unmarshal(file, &projects)

	for _, project := range projects {
		for _, task := range project.Tasks {
			if task.User_id == user_id {
				if task.Completed {
					completed_tasks++
				}
			}	
		}
	}

	fmt.Print(completed_tasks)
}
