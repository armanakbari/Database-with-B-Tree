//
// Created by Arman on 2/4/2022.
//
#include "BTree.h"
#ifndef PROJECT_TABLE_H
#define PROJECT_TABLE_H
#include "vector"
#include "Hashing.h"
class Table{
public:
    string name;
    int column_numbers;
    vector<vector<string>> name_type_list;
    vector<int> copys_of_id;
    vector<Node> select_answer_before_sort;
    BTree *btrees;
    string hashtable[999999];
    int idlist[500];
    Table(){
        for (int i = 0; i < 25; ++i)
            hashtable[i] = '0'+i;
    }
    int getId(){
        for (int i = 1; i < 500; ++i) {
            if(idlist[i] == 0) {
                idlist[i] = 1;
                return i;
            }
        }
        return -1;
    }
    void btreenode_traverse_for_deletion(int ind, BTreeNode *btn,int op, int rightside){
        int i;
        for (i = 0; i < btn->n; i++) {
            if (btn->leaf == false)
                btreenode_traverse_for_deletion(ind, btn->nextPtr[i], op, rightside);
            if(op == 0){
                if(btn->keys[i].data == rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        btrees[(ind + j)%(column_numbers+1)].remove(temp);
                        if(btrees[(ind+j)%(column_numbers+1)].name == "id")
                            idlist[temp2.data] = 0;
                        temp = *(temp2.nextField);
                    }
                    i = 0;
                    //btn = btrees[ind].root;
                }
            }
            else if(op == 1){
                if(btn->keys[i].data < rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        btrees[(ind + j)%(column_numbers+1)].remove(temp);
                        if(btrees[(ind+j)%(column_numbers+1)].name == "id")
                            idlist[temp2.data] = 0;
                        temp = *(temp2.nextField);
                    }
                    i = 0;
                    //btn = btrees[ind].root;
                }
            }
            else if(op == 2){
                if(btn->keys[i].data > rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        btrees[(ind + j)%(column_numbers+1)].remove(temp);
                        if(btrees[(ind+j)%(column_numbers+1)].name == "id")
                            idlist[temp2.data] = 0;
                        temp = *(temp2.nextField);
                    }
                    i = 0;
                    //btn = btrees[ind].root;
                }
            }
        }
        if (btn->leaf == false) {
            btreenode_traverse_for_deletion(ind, btn->nextPtr[i], op, rightside);
        }
    }
    void btree_traverse_for_deletion(int ind, int op, int rightside) {
        if (btrees[ind].root != NULL)
            btreenode_traverse_for_deletion(ind, btrees[ind].root, op, rightside);
    }
    void btreenode_traverse_for_deletion_and(int ind, BTreeNode *btn,int op, int rightside,int ind2,int op2, int rightside2){
        int i;
        for (i = 0; i < btn->n; i++) {
            if (btn->leaf == false)
                btreenode_traverse_for_deletion_and(ind, btn->nextPtr[i], op, rightside, ind2, op2, rightside2);
            if(op == 0){
                if(btn->keys[i].data == rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        int hazf = 0;
                        if( ((ind + j)%(column_numbers+1)) == ind2 ){
                            if(op2 == 0){
                                if(temp.data == rightside2)
                                    hazf = 1;
                            }else if(op2 == 1){
                                if(temp.data < rightside2)
                                    hazf = 1;
                            }else if(op2 == 2){
                                if(temp.data > rightside2)
                                    hazf = 1;
                            }
                        }
                        if(hazf == 1){
                            Node temp_second = btn->keys[i];
                            for (int b = 0; b < column_numbers+1; ++b) {
                                Node temp_second2 = temp_second;
                                btrees[(ind + b)%(column_numbers+1)].remove(temp_second);
                                if(btrees[(ind+b)%(column_numbers+1)].name == "id")
                                    idlist[temp_second2.data] = 0;
                                temp_second = *(temp_second2.nextField);
                            }
                        }
                        temp = *(temp2.nextField);
                    }
                    //i = 0;
                    //btn = btrees[ind].root;
                }
            }
            else if(op == 1){
                if(btn->keys[i].data < rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        int hazf = 0;
                        if( ((ind + j)%(column_numbers+1)) == ind2 ){
                            if(op2 == 0){
                                if(temp.data == rightside2)
                                    hazf = 1;
                            }else if(op2 == 1){
                                if(temp.data < rightside2)
                                    hazf = 1;
                            }else if(op2 == 2){
                                if(temp.data > rightside2)
                                    hazf = 1;
                            }
                        }
                        if(hazf == 1){
                            Node temp_second = btn->keys[i];
                            for (int b = 0; b < column_numbers+1; ++b) {
                                Node temp_second2 = temp_second;
                                btrees[(ind + b)%(column_numbers+1)].remove(temp_second);
                                if(btrees[(ind+b)%(column_numbers+1)].name == "id")
                                    idlist[temp_second2.data] = 0;
                                temp_second = *(temp_second2.nextField);
                            }
                        }
                        temp = *(temp2.nextField);
                    }
                    //i = 0;
                    //btn = btrees[ind].root;
                }
            }
            else if(op == 2){
                if(btn->keys[i].data > rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        int hazf = 0;
                        if( ((ind + j)%(column_numbers+1)) == ind2 ){
                            if(op2 == 0){
                                if(temp.data == rightside2)
                                    hazf = 1;
                            }else if(op2 == 1){
                                if(temp.data < rightside2)
                                    hazf = 1;
                            }else if(op2 == 2){
                                if(temp.data > rightside2)
                                    hazf = 1;
                            }
                        }
                        if(hazf == 1){
                            Node temp_second = btn->keys[i];
                            for (int b = 0; b < column_numbers+1; ++b) {
                                Node temp_second2 = temp_second;
                                btrees[(ind + b)%(column_numbers+1)].remove(temp_second);
                                if(btrees[(ind+b)%(column_numbers+1)].name == "id")
                                    idlist[temp_second2.data] = 0;
                                temp_second = *(temp_second2.nextField);
                            }
                        }
                        temp = *(temp2.nextField);
                    }
                    //i = 0;
                    //btn = btrees[ind].root;
                }
            }
        }
        if (btn->leaf == false) {
            btreenode_traverse_for_deletion_and(ind, btn->nextPtr[i], op, rightside,ind2, op2, rightside2);
        }
    }
    void btree_traverse_for_deletion_and(int ind, int op, int rightside,int ind2, int op2, int rightside2) {
        if (btrees[ind].root != NULL && btrees[ind2].root != NULL)
            btreenode_traverse_for_deletion_and(ind, btrees[ind].root, op, rightside,ind2, op2, rightside2);
    }
    void btreenode_traverse_for_update(int ind, BTreeNode *btn,int update_list[], int op, int rightside){
        int i;
        for (i = 0; i < btn->n; i++) {
            if (btn->leaf == false)
                btreenode_traverse_for_update(ind, btn->nextPtr[i], update_list, op, rightside);
            if(op == 0){
                if(btn->keys[i].data == rightside) {
                    int update_id_founder_index = 0;
                    Node temp = btn->keys[i];
                    while(btrees[(ind + update_id_founder_index)%(column_numbers+1)].name != "id"){
                        temp = *(temp.nextField);
                        update_id_founder_index++;
                    }
                    copys_of_id.push_back(temp.data);
                    temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        btrees[(ind + j)%(column_numbers+1)].remove(temp);
                        if(btrees[(ind+j)%(column_numbers+1)].name == "id")
                            idlist[temp2.data] = 0;
                        temp = *(temp2.nextField);
                    }
                    i = 0;
                    //btn = btrees[ind].root;
                }
            }
            else if(op == 1){

                if(btn->keys[i].data < rightside) {
                    int update_id_founder_index = 0;
                    Node temp = btn->keys[i];
                    while(btrees[(ind + update_id_founder_index)%(column_numbers+1)].name != "id"){
                        temp = *(temp.nextField);
                        update_id_founder_index++;
                    }
                    copys_of_id.push_back(temp.data);
                    temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        btrees[(ind + j)%(column_numbers+1)].remove(temp);
                        if(btrees[(ind+j)%(column_numbers+1)].name == "id")
                            idlist[temp2.data] = 0;
                        temp = *(temp2.nextField);
                    }
                    i = 0;
                    //btn = btrees[ind].root;
                }
            }
            else if(op == 2){
                if(btn->keys[i].data > rightside) {
                    int update_id_founder_index = 0;
                    Node temp = btn->keys[i];
                    while(btrees[(ind + update_id_founder_index)%(column_numbers+1)].name != "id"){
                        temp = *(temp.nextField);
                        update_id_founder_index++;
                    }
                    copys_of_id.push_back(temp.data);
                    temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        btrees[(ind + j)%(column_numbers+1)].remove(temp);
                        if(btrees[(ind+j)%(column_numbers+1)].name == "id")
                            idlist[temp2.data] = 0;
                        temp = *(temp2.nextField);
                    }
                    i = 0;
                    //btn = btrees[ind].root;
                }
            }
        }
        if (btn->leaf == false)
            btreenode_traverse_for_update(ind, btn->nextPtr[i], update_list, op, rightside);
    }
    void btree_traverse_for_update(int ind, int update_list[], int op, int rightside) {
        if (btrees[ind].root != NULL)
            btreenode_traverse_for_update(ind, btrees[ind].root, update_list, op, rightside);
    }
    void btreenode_traverse_for_update_and(int ind, BTreeNode *btn,int update_list[], int op, int rightside,int ind2, int op2, int rightside2){
        int i;
        for (i = 0; i < btn->n; i++) {
            if (btn->leaf == false)
                btreenode_traverse_for_update_and(ind, btn->nextPtr[i], update_list, op, rightside,ind2, op2, rightside2);
            if(op == 0){
                if(btn->keys[i].data == rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        int uphazf = 0;
                        if( ((ind+j)%(column_numbers+1)) == ind2){
                            if(op2 == 0){
                                if(temp.data == rightside2)
                                    uphazf = 1;
                            }else if(op2 == 1){
                                if(temp.data < rightside2)
                                    uphazf = 1;
                            }else if(op2 == 2){
                                if(temp.data > rightside2)
                                    uphazf = 1;
                            }
                        }
                        if(uphazf == 1){
                            Node temp_second = btn->keys[i];
                            for (int b = 0; b < column_numbers+1; ++b) {
                                if(btrees[(ind+b)%(column_numbers+1)].name == "id") {
                                    idlist[temp_second.data] = 0;
                                    copys_of_id.push_back(temp_second.data);
                                }
                                Node temp_second2 = temp_second;
                                btrees[(ind + b)%(column_numbers+1)].remove(temp_second);
                                temp_second = *(temp_second2.nextField);
                            }
                        }
                        temp = *(temp2.nextField);
                    }
                    //i = 0;
                    //btn = btrees[ind].root;
                }
            }
            else if(op == 1){
                if(btn->keys[i].data < rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        int uphazf = 0;
                        if( ((ind+j)%(column_numbers+1)) == ind2){
                            if(op2 == 0){
                                if(temp.data == rightside2)
                                    uphazf = 1;
                            }else if(op2 == 1){
                                if(temp.data < rightside2)
                                    uphazf = 1;
                            }else if(op2 == 2){
                                if(temp.data > rightside2)
                                    uphazf = 1;
                            }
                        }
                        if(uphazf == 1){
                            Node temp_second = btn->keys[i];
                            for (int b = 0; b < column_numbers+1; ++b) {
                                if(btrees[(ind+b)%(column_numbers+1)].name == "id") {
                                    idlist[temp_second.data] = 0;
                                    copys_of_id.push_back(temp_second.data);
                                }
                                Node temp_second2 = temp_second;
                                btrees[(ind + b)%(column_numbers+1)].remove(temp_second);
                                temp_second = *(temp_second2.nextField);
                            }
                        }
                        temp = *(temp2.nextField);
                    }
                    //i = 0;
                    //btn = btrees[ind].root;
                }
            }
            else if(op == 2){
                if(btn->keys[i].data > rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        int uphazf = 0;
                        if( ((ind+j)%(column_numbers+1)) == ind2){
                            if(op2 == 0){
                                if(temp.data == rightside2)
                                    uphazf = 1;
                            }else if(op2 == 1){

                                if(temp.data < rightside2)
                                    uphazf = 1;
                            }else if(op2 == 2){
                                if(temp.data > rightside2)
                                    uphazf = 1;
                            }
                        }
                        if(uphazf == 1){
                            cout<<"done"<<endl;
                            Node temp_second = btn->keys[i];
                            for (int b = 0; b < column_numbers+1; ++b) {
                                if(btrees[(ind+b)%(column_numbers+1)].name == "id") {
                                    idlist[temp_second.data] = 0;
                                    copys_of_id.push_back(temp_second.data);
                                }
                                Node temp_second2 = temp_second;
                                btrees[(ind + b)%(column_numbers+1)].remove(temp_second);
                                temp_second = *(temp_second2.nextField);
                            }
                        }
                        temp = *(temp2.nextField);
                    }
                    //i = 0;
                    //btn = btrees[ind].root;
                }
            }
        }
        if (btn->leaf == false)
            btreenode_traverse_for_update_and(ind, btn->nextPtr[i], update_list, op, rightside,ind2, op2, rightside2);
    }
    void btree_traverse_for_update_and(int ind, int update_list[], int op, int rightside, int ind2, int op2, int rightside2) {
        if (btrees[ind].root != NULL && btrees[ind2].root != NULL)
            btreenode_traverse_for_update_and(ind, btrees[ind].root, update_list, op, rightside, ind2, op2, rightside2);
    }
    void btreenode_traverse_for_select(int ind, BTreeNode *btn,vector<string> select_tree_list, int op, int rightside){
        int i;
        for (i = 0; i < btn->n; i++) {
            if (btn->leaf == false)
                btreenode_traverse_for_select(ind, btn->nextPtr[i], select_tree_list, op, rightside);
            if(op == 0){
                if(btn->keys[i].data == rightside) {
                    int select_id_founder_index = 0;
                    Node temp = btn->keys[i];
                    while(btrees[(ind + select_id_founder_index)%(column_numbers+1)].name != "id"){
                        temp = *(temp.nextField);
                        select_id_founder_index++;
                    }
                    int select_same_flag = 0;
                    for (int k = 0; k < select_answer_before_sort.size(); ++k) {
                        if(temp.data == select_answer_before_sort[k].data)
                            select_same_flag = 1;
                    }
                    if(select_same_flag == 0)
                        select_answer_before_sort.push_back(temp);
                }
            }
            else if(op == 1){
                if(btn->keys[i].data < rightside) {
                    int select_id_founder_index = 0;
                    Node temp = btn->keys[i];
                    while(btrees[(ind + select_id_founder_index)%(column_numbers+1)].name != "id"){
                        temp = *(temp.nextField);
                        select_id_founder_index++;
                    }
                    int select_same_flag = 0;
                    for (int k = 0; k < select_answer_before_sort.size(); ++k) {
                        if(temp.data == select_answer_before_sort[k].data)
                            select_same_flag = 1;
                    }
                    if(select_same_flag == 0)
                    select_answer_before_sort.push_back(temp);
                }
            }
            else if(op == 2){
                if(btn->keys[i].data > rightside) {
                    int select_id_founder_index = 0;
                    Node temp = btn->keys[i];
                    while(btrees[(ind + select_id_founder_index)%(column_numbers+1)].name != "id"){
                        temp = *(temp.nextField);
                        select_id_founder_index++;
                    }
                    int select_same_flag = 0;
                    for (int k = 0; k < select_answer_before_sort.size(); ++k) {
                        if(temp.data == select_answer_before_sort[k].data)
                            select_same_flag = 1;
                    }
                    if(select_same_flag == 0)
                    select_answer_before_sort.push_back(temp);
                }
            }
        }
        if (btn->leaf == false)
            btreenode_traverse_for_select(ind, btn->nextPtr[i], select_tree_list, op, rightside);
    }
    void btree_traverse_for_select(int ind, vector<string> select_tree_list, int op, int rightside) {
        if (btrees[ind].root != NULL)
            btreenode_traverse_for_select(ind, btrees[ind].root, select_tree_list, op, rightside);
    }
    void btreenode_traverse_for_select_and(int ind, BTreeNode *btn,vector<string> select_tree_list, int op, int rightside,int ind2, int op2, int rightside2){
        int i;
        for (i = 0; i < btn->n; i++) {
            if (btn->leaf == false)
                btreenode_traverse_for_select_and(ind, btn->nextPtr[i], select_tree_list, op, rightside, ind2, op2, rightside2);
            if(op == 0){
                if(btn->keys[i].data == rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        int select_flag = 0;
                        if( ((ind+j)%(column_numbers+1)) == ind2){
                            if(op2 == 0){
                                if(temp.data == rightside2)
                                    select_flag = 1;
                            }else if(op2 == 1){
                                if(temp.data < rightside2)
                                    select_flag = 1;
                            }else if(op2 == 2){
                                if(temp.data > rightside2)
                                    select_flag = 1;
                            }
                        }
                        if(select_flag == 1){
                            temp = btn->keys[i];
                            int select_id_founder_index = 0;
                            while(btrees[(ind + select_id_founder_index)%(column_numbers+1)].name != "id"){
                                temp = *(temp.nextField);
                                select_id_founder_index++;
                            }
                            int select_same_flag = 0;
                            for (int k = 0; k < select_answer_before_sort.size(); ++k) {
                                if(temp.data == select_answer_before_sort[k].data)
                                    select_same_flag = 1;
                            }
                            if(select_same_flag == 0)
                                select_answer_before_sort.push_back(temp);
                            break;
                        }
                        temp = *(temp2.nextField);
                    }
                }
            }
            else if(op == 1){
                if(btn->keys[i].data < rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        int select_flag = 0;
                        if( ((ind+j)%(column_numbers+1)) == ind2){
                            if(op2 == 0){
                                if(temp.data == rightside2)
                                    select_flag = 1;
                            }else if(op2 == 1){
                                if(temp.data < rightside2)
                                    select_flag = 1;
                            }else if(op2 == 2){
                                if(temp.data > rightside2)
                                    select_flag = 1;
                            }
                        }
                        if(select_flag == 1){
                            temp = btn->keys[i];
                            int select_id_founder_index = 0;
                            while(btrees[(ind + select_id_founder_index)%(column_numbers+1)].name != "id"){
                                temp = *(temp.nextField);
                                select_id_founder_index++;
                            }
                            int select_same_flag = 0;
                            for (int k = 0; k < select_answer_before_sort.size(); ++k) {
                                if(temp.data == select_answer_before_sort[k].data)
                                    select_same_flag = 1;
                            }
                            if(select_same_flag == 0)
                                select_answer_before_sort.push_back(temp);
                            break;
                        }
                        temp = *(temp2.nextField);
                    }
                }
            }
            else if(op == 2){
                if(btn->keys[i].data > rightside) {
                    Node temp = btn->keys[i];
                    for (int j = 0; j < column_numbers+1; ++j) {
                        Node temp2 = temp;
                        int select_flag = 0;
                        if( ((ind+j)%(column_numbers+1)) == ind2){
                            if(op2 == 0){
                                if(temp.data == rightside2)
                                    select_flag = 1;
                            }else if(op2 == 1){
                                if(temp.data < rightside2)
                                    select_flag = 1;
                            }else if(op2 == 2){
                                if(temp.data > rightside2)
                                    select_flag = 1;
                            }
                        }
                        if(select_flag == 1){
                            temp = btn->keys[i];
                            int select_id_founder_index = 0;
                            while(btrees[(ind + select_id_founder_index)%(column_numbers+1)].name != "id"){
                                temp = *(temp.nextField);
                                select_id_founder_index++;
                            }
                            int select_same_flag = 0;
                            for (int k = 0; k < select_answer_before_sort.size(); ++k) {
                                if(temp.data == select_answer_before_sort[k].data)
                                    select_same_flag = 1;
                            }
                            if(select_same_flag == 0)
                                select_answer_before_sort.push_back(temp);
                            break;
                        }
                        temp = *(temp2.nextField);
                    }
                }
            }
        }
        if (btn->leaf == false)
            btreenode_traverse_for_select_and(ind, btn->nextPtr[i], select_tree_list, op, rightside, ind2, op2, rightside2);
    }
    void btree_traverse_for_select_and(int ind, vector<string> select_tree_list, int op, int rightside, int ind2, int op2, int rightside2) {
        if (btrees[ind].root != NULL && btrees[ind2].root != NULL)
            btreenode_traverse_for_select_and(ind, btrees[ind].root, select_tree_list, op, rightside,ind2, op2, rightside2);
    }
    void check_input_type(string input, string type){
        if(type == "string"){
            for (int i = 0; i < input.length(); ++i) {
                if (!((input[i] >= 'a' && input[i] <= 'z') || input[i] == '\"' || (input[i] >= '0' && input[i] <= '9')))
                    cout<<input[i]<<"!!!!!!! your input must be an string !!!!!!!!!"<<endl;
            }
        }else if(type == "int"){
            for (int i = 0; i < input.length(); ++i) {
                if(input[i] < '0' || input[i] > '9')
                    cout<<"!!!!!!! your input must be an integer !!!!!!!!!"<<endl;
            }
        }else if(type == "timestamp"){
            for (int i = 0; i < input.length(); ++i) {
                if(!((input[i] >= '0' && input[i] <= '9') || (input[i] == '/')))
                    cout<<"!!!!!!! your input must be an timestamp !!!!!!!!!"<<endl;
            }
        }
    }
    void insert(string query,int index_on_quiery){
        Node *mainNodeRecord = new Node[column_numbers+1];
        string record[column_numbers];
        int record_index = 0;
        for (int j = 0; j < column_numbers; ++j) {
            mainNodeRecord[j].data = 0;
            mainNodeRecord[j].nextField = NULL;
        }
        int jj = index_on_quiery;
        while(record_index != column_numbers) {
            while(query[jj] == ' ')
                jj++;
            while(query[jj] != ' ' && query[jj] != ',' && query[jj] != ')'){
                record[record_index] += query[jj];
                jj++;
            }
            if(!record[record_index].empty())
                record_index++;
            if(query[jj] != ')'){
                jj++;
            }else
                break;
        }
        for (int i = 0; i < column_numbers; ++i) {
            check_input_type(record[i], name_type_list[i][1]);
        }
        mainNodeRecord[0].data = getId();
        for (int j = 0; j < column_numbers; ++j) {
            if(name_type_list[j][1] == "string")
                mainNodeRecord[j+1].data = hashh(record[j]);
            else if(name_type_list[j][1] == "int")
                mainNodeRecord[j+1].data = stoi(record[j]);
            else if(name_type_list[j][1] == "timestamp") {
                string year = "", month = "", day = "";
                int time_string_index = 0;
                while(record[j][time_string_index] != '/'){
                    year += record[j][time_string_index];
                    time_string_index++;
                    if(time_string_index == record[j].length()){
                        cout<<"!!!!!!! Invalid timestamp !!!!!!!!"<<endl;
                        return;
                    }
                }
                if(year == ""){
                    cout<<"!!!!!!! Invalid timestamp !!!!!!!!"<<endl;
                    return;
                }
                time_string_index++;
                while(record[j][time_string_index] != '/'){
                    month += record[j][time_string_index];
                    time_string_index++;
                    if(time_string_index == record[j].length()){
                        cout<<"!!!!!!! Invalid timestamp !!!!!!!!"<<endl;
                        return;
                    }
                }
                if(month == ""){
                    cout<<"!!!!!!! Invalid timestamp !!!!!!!!"<<endl;
                    return;
                }
                time_string_index++;
                while(time_string_index < record[j].length()){
                    day += record[j][time_string_index];
                    time_string_index++;
                }
                mainNodeRecord[j+1].data = hash_timestamp(year,month,day);
            }
        }
        for (int j = 0; j < column_numbers+1; ++j) {
            if(j != column_numbers)
                mainNodeRecord[j].nextField = &mainNodeRecord[j+1];
            else
                mainNodeRecord[j].nextField = &mainNodeRecord[0];
        }
        for (int j = 0; j < column_numbers; ++j) {
            hashtable[mainNodeRecord[j+1].data] = record[j];
        }
        for (int j = 0; j < column_numbers+1; ++j) {
            btrees[j].insert(mainNodeRecord[j]);
        }
    }
    void del(string condition_column_left, int opt, string condition_column_right){
        for (int j = 0; j < column_numbers; ++j) {
            if(btrees[j+1].name == condition_column_left){
                if(btrees[j+1].type == "int") {
                    btree_traverse_for_deletion(j+1, opt, stoi(condition_column_right));
                    btree_traverse_for_deletion(j+1, opt, stoi(condition_column_right));
                }else if(btrees[j+1].type == "string") {
                    int ar = hashh(condition_column_right), flag_2 = 0;
                    btree_traverse_for_deletion(j+1, opt, ar);
                    btree_traverse_for_deletion(j+1, opt, ar);
                }else if(btrees[j+1].type == "timestamp") {
                    string year = "", month = "", day = "";
                    int time_string_index = 0, flag_2 = 0;
                    while(condition_column_right[time_string_index] != '/'){
                        year += condition_column_right[time_string_index];
                        time_string_index++;
                    }
                    time_string_index++;
                    while(condition_column_right[time_string_index] != '/'){
                        month += condition_column_right[time_string_index];
                        time_string_index++;
                    }
                    time_string_index++;
                    while(time_string_index < condition_column_right.length()){
                        day += condition_column_right[time_string_index];
                        time_string_index++;
                    }
                    btree_traverse_for_deletion(j+1, opt, hash_timestamp(year, month, day));
                    btree_traverse_for_deletion(j+1, opt, hash_timestamp(year, month, day));
                }
                break;
            }
        }
    }
    void del_and(string condition_column_left, int opt, string condition_column_right,
                 string condition_column_left2, int opt2, string condition_column_right2){
        int hashed_condition_rightside = 0, hashed_condition_rightside2 = 0;
        for (int j = 0; j < column_numbers; ++j) {
            if(btrees[j+1].name == condition_column_left){
                for (int i = 0; i < column_numbers; ++i) {
                    if(btrees[i+1].name == condition_column_left2){
                        if(btrees[j+1].type == "int")
                            hashed_condition_rightside = stoi(condition_column_right);
                        else if(btrees[j+1].type == "string")
                            hashed_condition_rightside = hashh(condition_column_right);
                        else if(btrees[j+1].type == "timestamp") {
                            string year = "", month = "", day = "";
                            int time_string_index = 0;
                            while(condition_column_right[time_string_index] != '/'){
                                year += condition_column_right[time_string_index];
                                time_string_index++;
                            }
                            time_string_index++;
                            while(condition_column_right[time_string_index] != '/'){
                                month += condition_column_right[time_string_index];
                                time_string_index++;
                            }
                            time_string_index++;
                            while(time_string_index < condition_column_right.length()){
                                day += condition_column_right[time_string_index];
                                time_string_index++;
                            }
                            hashed_condition_rightside = hash_timestamp(year, month, day);
                        }
                        if(btrees[i+1].type == "int")
                            hashed_condition_rightside2 = stoi(condition_column_right2);
                        else if(btrees[i+1].type == "string")
                            hashed_condition_rightside2 = hashh(condition_column_right2);
                        else if(btrees[i+1].type == "timestamp") {
                            string year = "", month = "", day = "";
                            int time_string_index = 0;
                            while(condition_column_right2[time_string_index] != '/'){
                                year += condition_column_right2[time_string_index];
                                time_string_index++;
                            }
                            time_string_index++;
                            while(condition_column_right2[time_string_index] != '/'){
                                month += condition_column_right2[time_string_index];
                                time_string_index++;
                            }
                            time_string_index++;
                            while(time_string_index < condition_column_right.length()){
                                day += condition_column_right2[time_string_index];
                                time_string_index++;
                            }
                            hashed_condition_rightside2 = hash_timestamp(year, month, day);
                        }
                        btree_traverse_for_deletion_and(j+1, opt, hashed_condition_rightside,i+1, opt2, hashed_condition_rightside2);
                        btree_traverse_for_deletion_and(j+1, opt, hashed_condition_rightside,i+1, opt2, hashed_condition_rightside2);
                        break;
                    }
                }
            }
        }
    }
    void update_helper(string update_condition_left, string update_record[],int hashed_update_record[], int update_opt, int hashed_update_condition_rightside){
        for (int j = 0; j < column_numbers+1; ++j) {
            if(btrees[j].name == update_condition_left){
                btree_traverse_for_update(j, hashed_update_record, update_opt, hashed_update_condition_rightside);
                btree_traverse_for_update(j, hashed_update_record, update_opt, hashed_update_condition_rightside);
                while(!copys_of_id.empty()){
                    int copys_of_id_size = copys_of_id.size();
                    Node *updateNode = new Node[column_numbers+1];
                    updateNode[0].data = copys_of_id[copys_of_id_size-1];
                    copys_of_id.pop_back();
                    for (int k = 0; k < column_numbers; ++k) {
                        updateNode[k+1].data = hashed_update_record[k];
                    }
                    for (int k = 0; k < column_numbers+1; ++k) {
                        if(k != column_numbers)
                            updateNode[k].nextField = &updateNode[k+1];
                        else
                            updateNode[k].nextField = &updateNode[0];
                    }
                    for (int k = 0; k < column_numbers; ++k) {
                        hashtable[updateNode[k+1].data] = update_record[k];
                    }
                    for (int k = 0; k < column_numbers+1; ++k) {
                        btrees[k].insert(updateNode[k]);
                    }
                }
                break;
            }
        }
    }
    void update_helper_and(string update_condition_left, string update_record[],int hashed_update_record[], int update_opt, int hashed_update_condition_rightside,
                           string update_condition_left2, int update_opt2, int hashed_update_condition_rightside2){
        for (int j = 0; j < column_numbers+1; ++j) {
            if(btrees[j].name == update_condition_left){
                for (int i = 0; i < column_numbers+1; ++i) {
                    if(btrees[i].name == update_condition_left2){
                        btree_traverse_for_update_and(j, hashed_update_record, update_opt, hashed_update_condition_rightside, i, update_opt2, hashed_update_condition_rightside2);
                        btree_traverse_for_update_and(j, hashed_update_record, update_opt, hashed_update_condition_rightside, i, update_opt2, hashed_update_condition_rightside2);
                        while(!copys_of_id.empty()){
                            int copys_of_id_size = copys_of_id.size();
                            Node *updateNode = new Node[column_numbers+1];
                            updateNode[0].data = copys_of_id[copys_of_id_size-1];
                            copys_of_id.pop_back();
                            for (int k = 0; k < column_numbers; ++k) {
                                updateNode[k+1].data = hashed_update_record[k];
                            }
                            for (int k = 0; k < column_numbers+1; ++k) {
                                if(k != column_numbers)
                                    updateNode[k].nextField = &updateNode[k+1];
                                else
                                    updateNode[k].nextField = &updateNode[0];
                            }
                            for (int k = 0; k < column_numbers; ++k) {
                                hashtable[updateNode[k+1].data] = update_record[k];
                            }
                            for (int k = 0; k < column_numbers+1; ++k) {
                                btrees[k].insert(updateNode[k]);
                            }
                        }
                        break;
                    }
                }

            }
        }
    }
    void update(string query, int update_index) {
        int record_counter = 0, update_record_inx = 0, update_opt = 0, update_opt2 = 0;
        string update_record[column_numbers];
        string update_condition_left = "", update_condition_right = "",
                update_condition_left2 = "", update_condition_right2 = "",
                update_condition_combination = "";
        while (record_counter < column_numbers) {
            while (query[update_index] == ' ')
                update_index++;
            while (query[update_index] != ' ' && query[update_index] != ',' && query[update_index] != ')') {
                update_record[update_record_inx] += query[update_index];
                update_index++;
            }
            while (query[update_index] == ' ')
                update_index++;
            record_counter++;
            update_record_inx++;
            if (query[update_index] == ',')
                update_index++;
            else
                break;
        }
        if (query[update_index] != ')') {
            cout << "!!!!!!! Syntax ERROR !!!!!!!" << endl;
            return;
        }
        update_index++;
        while (query[update_index] == ' ')
            update_index++;
        string update_syntax_tmp = "";
        while (query[update_index] != ' ') {
            update_syntax_tmp += query[update_index];
            update_index++;
        }
        if (update_syntax_tmp != "WHERE") {
            cout << "!!!!!!! Syntax ERROR !!!!!!!" << endl;
            return;
        }
        while (query[update_index] == ' ')
            update_index++;
        while (query[update_index] != '=' && query[update_index] != '>' && query[update_index] != '<') {
            update_condition_left += query[update_index];
            update_index++;
            if (update_index == query.length()) {
                cout << "!!!!!!! Syntax ERROR !!!!!!!" << endl;
                return;
            }
        }
        if (query[update_index] == '=') {
            if (query[update_index + 1] != '=') {
                cout << "!!!!!!! Syntax ERROR !!!!!!!" << endl;
                return;
            }
            update_opt = 0;
            update_index += 2; // because there would be two =
            while (query[update_index] != ' ' && update_index < query.length()) {
                update_condition_right += query[update_index];
                update_index++;
            }
        } else if (query[update_index] == '<') {
            update_opt = 1;
            update_index++;
        } else if (query[update_index] == '>') {
            update_opt = 2;
            update_index++;
        }
        while ((query[update_index] != ' ') && (update_index < query.length())) {
            update_condition_right += query[update_index];
            update_index++;
        }
        if (query[update_index] == ' ') { //This means we have a second condition
            while (query[update_index] == ' ')
                update_index++;
            update_condition_combination = query[update_index];
            update_index++;
            while (query[update_index] == ' ')
                update_index++;
            while (query[update_index] != ' ' && query[update_index] != '=' && query[update_index] != '>' &&
                   query[update_index] != '<') {
                update_condition_left2 += query[update_index];
                update_index++;
            }
            while (query[update_index] == ' ')
                update_index++;
            if (query[update_index] == '=') {
                if (query[update_index + 1] != '=') {
                    cout << "!!!!!! Syntax ERROR !!!!!!!!" << endl;
                    return;
                }
                update_opt2 = 0;
                update_index += 2;
            } else if (query[update_index] == '>') {
                update_opt2 = 2;
                update_index += 1;
            } else if (query[update_index] == '<') {
                update_opt2 = 1;
                update_index += 1;
            }
            while (update_index < query.length()) {
                update_condition_right2 += query[update_index];
                update_index++;
            }
        }
        /*cout << "update condition: " << endl
             << update_condition_left << " " << update_opt << " " << update_condition_right << endl
             << update_condition_left2 << " " << update_opt2 << " " << update_condition_right2 << endl
             << update_condition_combination<<endl;*/

        int hashed_update_record[column_numbers];
        int hashed_update_condition_rightside = 0, hashed_update_condition_rightside2 = 0;
        for (int j = 0; j < column_numbers; ++j) {
            if (name_type_list[j][1] == "int")
                hashed_update_record[j] = stoi(update_record[j]);
            else if (name_type_list[j][1] == "string")
                hashed_update_record[j] = hashh(update_record[j]);
            else if (name_type_list[j][1] == "timestamp") {
                string year = "", month = "", day = "";
                int time_string_index = 0;
                while (update_record[j][time_string_index] != '/') {
                    year += update_record[j][time_string_index];
                    time_string_index++;
                }
                time_string_index++;
                while (update_record[j][time_string_index] != '/') {
                    month += update_record[j][time_string_index];
                    time_string_index++;
                }
                time_string_index++;
                while (time_string_index < update_record[j].length()) {
                    day += update_record[j][time_string_index];
                    time_string_index++;
                }
                hashed_update_record[j] = hash_timestamp(year, month, day);
            }
        }
        for (int j = 0; j < column_numbers+1; ++j) {
            if (btrees[j].name == update_condition_left) {
                if (btrees[j].type == "int")
                    hashed_update_condition_rightside = stoi(update_condition_right);
                else if (btrees[j].type == "string")
                    hashed_update_condition_rightside = hashh(update_condition_right);
                else if (btrees[j].type == "timestamp") {
                    string year = "", month = "", day = "";
                    int time_string_index = 0;
                    while (update_condition_right[time_string_index] != '/') {
                        year += update_condition_right[time_string_index];
                        time_string_index++;
                    }
                    time_string_index++;
                    while (update_condition_right[time_string_index] != '/') {
                        month += update_condition_right[time_string_index];
                        time_string_index++;
                    }
                    time_string_index++;
                    while (time_string_index < update_condition_right.length()) {
                        day += update_condition_right[time_string_index];
                        time_string_index++;
                    }
                    hashed_update_condition_rightside = hash_timestamp(year, month, day);
                }

            }
        }
        for (int j = 0; j < column_numbers+1; ++j) {
            if (btrees[j].name == update_condition_left2) {
                if (btrees[j].type == "int")
                    hashed_update_condition_rightside2 = stoi(update_condition_right2);
                else if (btrees[j].type == "string")
                    hashed_update_condition_rightside2 = hashh(update_condition_right2);
                else if (btrees[j].type == "timestamp") {
                    string year = "", month = "", day = "";
                    int time_string_index = 0;
                    while (update_condition_right2[time_string_index] != '/') {
                        year += update_condition_right2[time_string_index];
                        time_string_index++;
                    }
                    time_string_index++;
                    while (update_condition_right2[time_string_index] != '/') {
                        month += update_condition_right2[time_string_index];
                        time_string_index++;
                    }
                    time_string_index++;
                    while (time_string_index < update_condition_right2.length()) {
                        day += update_condition_right2[time_string_index];
                        time_string_index++;
                    }
                    hashed_update_condition_rightside2 = hash_timestamp(year, month, day);
                }
            }
        }
        /*cout<<"table name : "<<name<<endl;
        cout<<"update information: "<<endl;
        for (int j = 0; j < column_numbers; ++j)
            cout<<update_record[j]<<", ";
        cout<<endl;
        for (int j = 0; j < column_numbers; ++j)
            cout<<hashed_update_record[j]<<" % ";
        cout<<update_condition_left<<" "<<update_opt<<" "<<update_condition_right<<endl;*/
        //now we have update_condition_left and right and opt it's time to update
        if (update_condition_combination == "|") {
            update_helper(update_condition_left, update_record, hashed_update_record, update_opt,
                          hashed_update_condition_rightside);
            update_helper(update_condition_left2, update_record, hashed_update_record, update_opt2,
                          hashed_update_condition_rightside2);
        }else if(update_condition_combination == "&"){
            update_helper_and(update_condition_left, update_record, hashed_update_record, update_opt, hashed_update_condition_rightside,
                          update_condition_left2, update_opt2, hashed_update_condition_rightside2);
        }else if(update_condition_combination == "")
            update_helper(update_condition_left, update_record, hashed_update_record, update_opt,
                          hashed_update_condition_rightside);
    }
    void select_helper(string select_condition_leftside, int select_opt, string select_condition_rightside, vector<string> select_list){
        for (int j = 0; j < column_numbers; ++j) {
            if(btrees[j+1].name == select_condition_leftside){
                int hashed_select_condition_rightside = 0;
                if(btrees[j+1].type == "int"){
                    hashed_select_condition_rightside = stoi(select_condition_rightside);
                }if(btrees[j+1].type == "string"){
                    hashed_select_condition_rightside = hashh(select_condition_rightside);
                }else if(btrees[j+1].type == "timestamp"){
                    string year = "", month = "", day = "";
                    int time_string_index = 0;
                    while(select_condition_rightside[time_string_index] != '/'){
                        year += select_condition_rightside[time_string_index];
                        time_string_index++;
                    }
                    time_string_index++;
                    while(select_condition_rightside[time_string_index] != '/'){
                        month += select_condition_rightside[time_string_index];
                        time_string_index++;
                    }
                    time_string_index++;
                    while(time_string_index < select_condition_rightside.length()){
                        day += select_condition_rightside[time_string_index];
                        time_string_index++;
                    }
                    hashed_select_condition_rightside = hash_timestamp(year,month,day);
                }
                btree_traverse_for_select(j+1, select_list, select_opt, hashed_select_condition_rightside);
                for (int q = 0; q < select_answer_before_sort.size()-1; q++) {
                    for (int p = 0; p < select_answer_before_sort.size() - q - 1; p++) {
                        Node tmp;
                        if (select_answer_before_sort[p].data > select_answer_before_sort[p + 1].data) {
                            tmp = select_answer_before_sort[p];
                            select_answer_before_sort[p] = select_answer_before_sort[p + 1];
                            select_answer_before_sort[p + 1] = tmp;
                        }
                    }
                }
                int sifi = 0;
                for (int k = 0; k < select_answer_before_sort.size(); ++k) {
                    Node select_temp_after_sort = select_answer_before_sort[k];
                    for (int l = 0; l < column_numbers + 1; ++l) {
                        for (int m = 0; m < select_list.size(); ++m) {
                            if(btrees[l%(column_numbers+1)].name == select_list[m]){
                                if(select_list[m] != "id") {
                                    if (btrees[l%(column_numbers+1)].type == "string") {
                                        for (int i1 = 1;i1 < hashtable[select_temp_after_sort.data].length() - 1; ++i1) {
                                            cout << hashtable[select_temp_after_sort.data][i1];
                                        }
                                        cout << " ";
                                    }else
                                        cout << hashtable[select_temp_after_sort.data] << " ";
                                }else
                                    cout<<select_temp_after_sort.data<<" ";
                                break;
                            }
                        }
                        select_temp_after_sort = *(select_temp_after_sort.nextField);
                    }
                    cout<<endl;
                }
            }
        }
    }
    void select_helper_and(string select_condition_leftside, int select_opt, string select_condition_rightside, vector<string> select_list,
                           string select_condition_leftside2, int select_opt2, string select_condition_rightside2){
        for (int j = 0; j < column_numbers; ++j) {
            if(btrees[j+1].name == select_condition_leftside){
                int hashed_select_condition_rightside = 0;
                if(btrees[j+1].type == "int"){
                    hashed_select_condition_rightside = stoi(select_condition_rightside);
                }if(btrees[j+1].type == "string"){
                    hashed_select_condition_rightside = hashh(select_condition_rightside);
                }else if(btrees[j+1].type == "timestamp"){
                    string year = "", month = "", day = "";
                    int time_string_index = 0;
                    while(select_condition_rightside[time_string_index] != '/'){
                        year += select_condition_rightside[time_string_index];
                        time_string_index++;
                    }
                    time_string_index++;
                    while(select_condition_rightside[time_string_index] != '/'){
                        month += select_condition_rightside[time_string_index];
                        time_string_index++;
                    }
                    time_string_index++;
                    while(time_string_index < select_condition_rightside.length()){
                        day += select_condition_rightside[time_string_index];
                        time_string_index++;
                    }
                    hashed_select_condition_rightside = hash_timestamp(year,month,day);
                }
                for (int i = 0; i < column_numbers; ++i) {
                    if(btrees[i+1].name == select_condition_leftside2){

                        int hashed_select_condition_rightside2 = 0;
                        if(btrees[i+1].type == "int"){
                            hashed_select_condition_rightside2 = stoi(select_condition_rightside2);
                        }if(btrees[i+1].type == "string"){
                            hashed_select_condition_rightside2 = hashh(select_condition_rightside2);
                        }else if(btrees[i+1].type == "timestamp"){
                            string year = "", month = "", day = "";
                            int time_string_index = 0;
                            while(select_condition_rightside2[time_string_index] != '/'){
                                year += select_condition_rightside2[time_string_index];
                                time_string_index++;
                            }
                            time_string_index++;
                            while(select_condition_rightside2[time_string_index] != '/'){
                                month += select_condition_rightside2[time_string_index];
                                time_string_index++;
                            }
                            time_string_index++;
                            while(time_string_index < select_condition_rightside2.length()){
                                day += select_condition_rightside2[time_string_index];
                                time_string_index++;
                            }
                            hashed_select_condition_rightside2 = hash_timestamp(year,month,day);
                        }

                        btree_traverse_for_select_and(j+1, select_list, select_opt, hashed_select_condition_rightside,
                                                          i+1, select_opt2, hashed_select_condition_rightside2);
                        for (int q = 0; q < select_answer_before_sort.size()-1; q++) {
                            for (int p = 0; p < select_answer_before_sort.size() - q - 1; p++) {
                                Node tmp;
                                if (select_answer_before_sort[p].data > select_answer_before_sort[p + 1].data) {
                                    tmp = select_answer_before_sort[p];
                                    select_answer_before_sort[p] = select_answer_before_sort[p + 1];
                                    select_answer_before_sort[p + 1] = tmp;
                                }
                            }
                        }
                        int sifi = 0;
                        for (int k = 0; k < select_answer_before_sort.size(); ++k) {
                            Node select_temp_after_sort = select_answer_before_sort[k];
                            for (int l = 0; l < column_numbers + 1; ++l) {
                                for (int m = 0; m < select_list.size(); ++m) {
                                    if(btrees[l%(column_numbers+1)].name == select_list[m]){
                                        if(select_list[m] != "id") {
                                            if (btrees[l%(column_numbers+1)].type == "string") {
                                                for (int i1 = 1;i1 < hashtable[select_temp_after_sort.data].length() - 1; ++i1) {
                                                    cout << hashtable[select_temp_after_sort.data][i1];
                                                }
                                                cout << " ";
                                            }else
                                                cout << hashtable[select_temp_after_sort.data] << " ";
                                        }else
                                            cout<<select_temp_after_sort.data<<" ";
                                        break;
                                    }
                                }
                                select_temp_after_sort = *(select_temp_after_sort.nextField);
                            }
                            cout<<endl;
                        }
                    }
                }
            }
        }
    }
    void select(string query){
        vector<string> select_list;
        string select_condition_leftside = "", select_condition_rightside = "",
               select_condition_combination = "",
               select_condition_leftside2 = "", select_condition_rightside2 = "";
        int select_opt = 0, select_opt2 = 0, select_index = 0;
        while(query[select_index] != ' ')
            select_index++;
        while(query[select_index] == ' ')
            select_index++;
        if(query[select_index] == '*'){
            for (int j = 0; j < column_numbers+1; ++j)
                select_list.push_back(btrees[j].name);
            select_index++;
        }
        else{
            while(query[select_index] == ' ' || query[select_index] == '(')
                select_index++;
            while(query[select_index] != ')'){
                string select_list_tmp = "";
                while(query[select_index] != ' ' && query[select_index] != ',' && query[select_index] != ')'){
                    select_list_tmp += query[select_index];
                    select_index++;
                }
                select_list.push_back(select_list_tmp);
                while(query[select_index] == ' ')
                    select_index++;
                if(query[select_index] == ','){
                    select_index++;
                    while(query[select_index] == ' ')
                        select_index++;
                }
            }
            select_index++;
        }
        while(query[select_index] == ' ')
            select_index++;
        while(query[select_index] != ' ')
            select_index++;
        while(query[select_index] == ' ')
            select_index++;
        while(query[select_index] != ' ')
            select_index++;
        while(query[select_index] == ' ')
            select_index++;
        while(query[select_index] != ' ')
            select_index++;
        while(query[select_index] == ' ')
            select_index++;
        while(query[select_index] != '=' && query[select_index] != ' ' && query[select_index] != '<' && query[select_index] != '>'){
            select_condition_leftside += query[select_index];
            select_index++;
        }
        while(query[select_index] == ' ')
            select_index++;
        if(query[select_index] == '='){
            select_opt = 0;
            select_index += 2;
        }else if(query[select_index] == '<'){
            select_opt = 1;
            select_index++;
        }else if(query[select_index] == '>'){
            select_opt = 2;
            select_index++;
        }
        while(query[select_index] == ' ')
            select_index++;
        while(query[select_index] != ' ' && select_index < query.length()){
            select_condition_rightside += query[select_index];
            select_index++;
        }
        if (query[select_index] == ' ') { //This means we have a second condition
            while (query[select_index] == ' ')
                select_index++;
            select_condition_combination = query[select_index];
            select_index++;
            while (query[select_index] == ' ')
                select_index++;
            while (query[select_index] != ' ' && query[select_index] != '=' && query[select_index] != '>' &&
                   query[select_index] != '<') {
                select_condition_leftside2 += query[select_index];
                select_index++;
            }
            while (query[select_index] == ' ')
                select_index++;
            if (query[select_index] == '=') {
                if (query[select_index + 1] != '=') {
                    cout << "!!!!!! Syntax ERROR !!!!!!!!" << endl;
                    return;
                }
                select_opt2 = 0;
                select_index += 2;
            } else if (query[select_index] == '>') {
                select_opt2 = 2;
                select_index += 1;
            } else if (query[select_index] == '<') {
                select_opt2 = 1;
                select_index += 1;
            }
            while (select_index < query.length()) {
                select_condition_rightside2 += query[select_index];
                select_index++;
            }
        }
        if(select_condition_combination == "|"){
            select_answer_before_sort.clear();
            select_helper(select_condition_leftside, select_opt, select_condition_rightside,select_list);
            select_helper(select_condition_leftside2, select_opt2, select_condition_rightside2,select_list);
        }else if(select_condition_combination == "&"){
            select_answer_before_sort.clear();
            select_helper_and(select_condition_leftside, select_opt, select_condition_rightside,select_list,
                              select_condition_leftside2, select_opt2, select_condition_rightside2);
        }else if(select_condition_combination == "") {
            select_answer_before_sort.clear();
            select_helper(select_condition_leftside, select_opt, select_condition_rightside,select_list);
        }
    }
    void trv(BTreeNode *tn) {
        int i;
        for (i = 0; i < tn->n; i++) {
            if (tn->leaf == false)
                trv(tn->nextPtr[i]);
            cout<<hashtable[tn->keys[i].data]<<" : "<<hashtable[tn->keys[i].nextField->data]<<", ";
        }
        if (tn->leaf == false)
            trv(tn->nextPtr[i]);
    }
    void print(){
        cout<<"name of table: "<<name<<endl;
        cout<<endl;
        for (int j = 0; j < column_numbers+1; ++j) {
            trv(btrees[j].root);
            cout<<endl;
        }
    }
};
#endif //PROJECT_TABLE_H
