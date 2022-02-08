#include <iostream>
#include "Table.h"
#include "vector"
void handler(string s[], int n, int table_numbers, string create_queries[]){
    Table *tables = new Table[table_numbers];
    string create_syntax_validation[2] = {"CREATE", "TABLE"};
    string create_type_validation[3] = {"string", "int", "timestamp"};
    for (int i = 0; i < table_numbers; ++i) {
        for (int j = 0; j < create_queries[i].length(); ++j) {
            int create_index = 0;
            string name = "";
            string syntax_checker = "";
            vector<vector<string>> name_type;
            vector<string> name_type_tmp;
            while(create_queries[i][j] != ' ') {
                syntax_checker += create_queries[i][j];
                j++;
            }
            if(syntax_checker != create_syntax_validation[0]){
                cout<<"!!!!!! Syntax ERROR 11 !!!!!!!"<<endl;
                return;
            }
            while(create_queries[i][j] == ' ')
                j++;
            syntax_checker = "";
            while(create_queries[i][j] != ' ') {
                syntax_checker += create_queries[i][j];
                j++;
            }
            if(syntax_checker != create_syntax_validation[1]){
                cout<<"!!!!!! Syntax ERROR 222 !!!!!!!"<<endl;
                return;
            }
            while(create_queries[i][j] == ' ')
                j++;
            while(create_queries[i][j] != ' '){
                name += create_queries[i][j];
                j++;
            }
            while(create_queries[i][j] == ' ')
                j++;
            if(create_queries[i][j] != '(' || create_queries[i][create_queries[i].length()-1] != ')') {
                cout << "!!!!!! Syntax ERROR 333!!!!!!!" << endl;
                return;
            }
            j++;//now we are on '(' so we pass it
            while(create_queries[i][j] != ')') {
                while (create_queries[i][j] == ' ')
                    j++;
                string name_type_first = "", name_type_second = "";
                while (create_queries[i][j] != ' ') {
                    name_type_first += create_queries[i][j];
                    j++;
                }
                while (create_queries[i][j] == ' ')
                    j++;
                while (create_queries[i][j] != ' ' && create_queries[i][j] != ',' && create_queries[i][j] != ')') {
                    name_type_second += create_queries[i][j];
                    j++;
                }
                if (create_queries[i][j] == ' ') {
                    while (create_queries[i][j] == ' ')
                        j++;
                }
                if (create_queries[i][j] == ',')
                    j++;
                if(name_type_second != "int" && name_type_second != "string" && name_type_second != "timestamp"){
                    cout<<"!!!!!! Syntax ERROR: Invalid data type. !!!!!!!!"<<endl;
                    return;
                }
                name_type_tmp.clear();
                name_type_tmp.push_back(name_type_first);
                name_type_tmp.push_back(name_type_second);
                name_type.push_back(name_type_tmp);
            }

            tables[i].name = name;
            tables[i].column_numbers = name_type.size();
            tables[i].name_type_list = name_type;
            tables[i].btrees = new BTree[tables[i].column_numbers+1];
            tables[i].btrees[0].name = "id";
            tables[i].btrees[0].type = "int";
            for (int k = 0; k < tables[i].column_numbers; ++k) {
                tables[i].btrees[k+1].name = name_type[k][0];
                tables[i].btrees[k+1].type = name_type[k][1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i][0] == 'I') {
            string insert_syntax_validation[3] = {"INSERT", "INTO", "VALUES"};
            string insert_table_name = "";
            string insert_syntax_tmp = "";
            int parantez_finder_index = 0;
            while (s[i][parantez_finder_index] != ' ') {
                insert_syntax_tmp += s[i][parantez_finder_index];
                parantez_finder_index++;
            }
            if (insert_syntax_tmp != insert_syntax_validation[0]) {
                cout << "!!!!!! Syntax ERROR !!!!!!!!" << endl;
                return;
            }
            while (s[i][parantez_finder_index] == ' ')
                parantez_finder_index++;
            insert_syntax_tmp = "";
            while (s[i][parantez_finder_index] != ' ') {
                insert_syntax_tmp += s[i][parantez_finder_index];
                parantez_finder_index++;
            }
            if (insert_syntax_tmp != insert_syntax_validation[1]) {
                cout << "!!!!!!! Syntax ERROR !!!!!!!!" << endl;
                return;
            }
            while (s[i][parantez_finder_index] == ' ')
                parantez_finder_index++;
            while (s[i][parantez_finder_index] != ' ') {
                insert_table_name += s[i][parantez_finder_index];
                parantez_finder_index++;
            }
            while (s[i][parantez_finder_index] == ' ')
                parantez_finder_index++;
            insert_syntax_tmp = "";
            while (s[i][parantez_finder_index] != ' ') {
                insert_syntax_tmp += s[i][parantez_finder_index];
                parantez_finder_index++;
            }
            if (insert_syntax_tmp != insert_syntax_validation[2]) {
                cout << "!!!!!!! Syntax ERROR !!!!!!!!" << endl;
                return;
            }
            while (s[i][parantez_finder_index] == ' ')
                parantez_finder_index++;
            // now we are on '('
            if (s[i][parantez_finder_index] != '(' || s[i][s[i].length() - 1] != ')') {
                cout << "!!!!!!! Syntax ERROR !!!!!!!!" << endl;
                return;
            }
            for (int j = 0; j < table_numbers; ++j) {
                if (tables[j].name == insert_table_name) {
                    tables[j].insert(s[i], parantez_finder_index + 1);
                    //tables[j].print();
                    break;
                }
            }
        }
        else if (s[i][0] == 'D') {
            int condition_finder_index = 0;
            string delete_syntax_validation[3] = {"DELETE", "FROM", "WHERE"};
            string delete_syntax_tmp = "";
            string delete_table_name = "";
            while (s[i][condition_finder_index] != ' ') {
                delete_syntax_tmp += s[i][condition_finder_index];
                condition_finder_index++;
            }
            if (delete_syntax_tmp != delete_syntax_validation[0]) {
                cout << "!!!!!! Syntax ERROR !!!!!!!!" << endl;
                return;
            }
            while (s[i][condition_finder_index] == ' ')
                condition_finder_index++;
            delete_syntax_tmp = "";
            while (s[i][condition_finder_index] != ' ') {
                delete_syntax_tmp += s[i][condition_finder_index];
                condition_finder_index++;
            }
            if (delete_syntax_tmp != delete_syntax_validation[1]) {
                cout << "!!!!!! Syntax ERROR !!!!!!!!" << endl;
                return;
            }
            while (s[i][condition_finder_index] == ' ')
                condition_finder_index++;
            while (s[i][condition_finder_index] != ' ') {
                delete_table_name += s[i][condition_finder_index];
                condition_finder_index++;
            }
            while (s[i][condition_finder_index] == ' ')
                condition_finder_index++;
            delete_syntax_tmp = "";
            while (s[i][condition_finder_index] != ' ') {
                delete_syntax_tmp += s[i][condition_finder_index];
                condition_finder_index++;
            }
            if (delete_syntax_tmp != delete_syntax_validation[2]) {
                cout << "!!!!!! Syntax ERROR !!!!!!!!" << endl;
                return;
            }
            while (s[i][condition_finder_index] == ' ')
                condition_finder_index++;
            string condition_column_left = "", condition_column_right = "",
                    condition_column_combination = "",
                    condition_column_left_2 = "", condition_column_right_2 = "";
            int opt = 0, opt2 = 0;// 0 for ==, 1 for <, 2 for >
            while (s[i][condition_finder_index] != '=' && s[i][condition_finder_index] != '>' &&
                   s[i][condition_finder_index] != '<' && s[i][condition_finder_index] != ' ') {
                condition_column_left += s[i][condition_finder_index];
                condition_finder_index++;
                if (condition_finder_index == s[i].length()) {
                    cout << "!!!!!! Syntax ERROR !!!!!!!!" << endl;
                    return;
                }
            }
            if (s[i][condition_finder_index] == ' ') {
                while (s[i][condition_finder_index] == ' ')
                    condition_finder_index++;
            }
            if (s[i][condition_finder_index] == '=') {
                if (s[i][condition_finder_index + 1] != '=') {
                    cout << "!!!!!! Syntax ERROR !!!!!!!!" << endl;
                    return;
                }
                opt = 0;
                condition_finder_index += 2;
            } else if (s[i][condition_finder_index] == '>') {
                opt = 2;
                condition_finder_index += 1;
            } else if (s[i][condition_finder_index] == '<') {
                opt = 1;
                condition_finder_index += 1;
            }
            while ((s[i][condition_finder_index] != ' ') && (condition_finder_index < s[i].length())) {
                condition_column_right += s[i][condition_finder_index];
                condition_finder_index++;
            }
            if (s[i][condition_finder_index] == ' ') { //This means we have a second condition
                while (s[i][condition_finder_index] == ' ')
                    condition_finder_index++;
                condition_column_combination = s[i][condition_finder_index];
                condition_finder_index++;
                while (s[i][condition_finder_index] == ' ')
                    condition_finder_index++;
                while (s[i][condition_finder_index] != ' ' && s[i][condition_finder_index] != '=' &&
                       s[i][condition_finder_index] != '>' && s[i][condition_finder_index] != '<') {
                    condition_column_left_2 += s[i][condition_finder_index];
                    condition_finder_index++;
                }
                while (s[i][condition_finder_index] == ' ')
                    condition_finder_index++;
                if (s[i][condition_finder_index] == '=') {
                    if (s[i][condition_finder_index + 1] != '=') {
                        cout << "!!!!!! Syntax ERROR !!!!!!!!" << endl;
                        return;
                    }
                    opt2 = 0;
                    condition_finder_index += 2;
                } else if (s[i][condition_finder_index] == '>') {
                    opt2 = 2;
                    condition_finder_index += 1;
                } else if (s[i][condition_finder_index] == '<') {
                    opt2 = 1;
                    condition_finder_index += 1;
                }
                while (condition_finder_index < s[i].length()) {
                    condition_column_right_2 += s[i][condition_finder_index];
                    condition_finder_index++;
                }
                /*cout<<"Conditions: "<<condition_column_left<<" "<<opt<<" "<<condition_column_right<<endl
                                    <<condition_column_combination<<endl
                                    <<condition_column_left_2<<" "<<opt2<<" "<<condition_column_right_2<<endl;
                */
            }
            //we should run a for loop over the mainTable and
            //find the table which has condition_column_left as its name
            //Then we will traverse the tree and delete the ones which are equal to condition_column_right
            //cout<<condition_column_left<<" "<<opt<<" "<<condition_column_right<<endl;
            for (int j = 0; j < table_numbers; ++j) {
                if (tables[j].name == delete_table_name) {
                    if (condition_column_combination == "") {
                        tables[j].del(condition_column_left, opt, condition_column_right);
                    } else if (condition_column_combination == "|") {
                        tables[j].del(condition_column_left, opt, condition_column_right);
                        tables[j].del(condition_column_left_2, opt2, condition_column_right_2);
                    } else if (condition_column_combination == "&") {
                        tables[j].del_and(condition_column_left, opt, condition_column_right,
                                          condition_column_left_2, opt2, condition_column_right_2);
                    }
                    break;
                }
            }
        }
        else if (s[i][0] == 'U') {
            string update_table_name;
            string update_syntax_validation[3] = {"UPDATE", "SET", "WHERE"};
            string update_syntax_tmp = "";
            int update_index = 0;
            while (s[i][update_index] != ' ') {
                update_syntax_tmp += s[i][update_index];
                update_index++;
            }
            if (update_syntax_tmp != update_syntax_validation[0]) {
                cout << "!!!!!!! Syntax ERROR !!!!!!!" << endl;
                return;
            }
            while (s[i][update_index] == ' ')
                update_index++;
            while (s[i][update_index] != ' ') {
                update_table_name += s[i][update_index];
                update_index++;
            }
            while (s[i][update_index] == ' ')
                update_index++;
            update_syntax_tmp = "";
            while (s[i][update_index] != ' ') {
                update_syntax_tmp += s[i][update_index];
                update_index++;
            }
            if (update_syntax_tmp != update_syntax_validation[1]) {
                cout << "!!!!!!! Syntax ERROR !!!!!!!" << endl;
                return;
            }
            while (s[i][update_index] == ' ')
                update_index++;
            if (s[i][update_index] != '(') {
                cout << "!!!!!!! Syntax ERROR !!!!!!!" << endl;
                return;
            }
            update_index++;
            while (s[i][update_index] == ' ')
                update_index++;
            for (int j = 0; j < table_numbers; ++j) {
                if (tables[j].name == update_table_name) {
                    tables[j].update(s[i], update_index);
                    //tables[j].print();
                    break;
                }
            }
        }
        else if (s[i][0] == 'S') {
            string select_tablename;
            string select_syntax_validation[3] = {"SELECT", "FROM", "WHERE"};
            string select_syntax_tmp = "";
            int select_tablename_index = 0;
            while (s[i][select_tablename_index] != ' ') {
                select_syntax_tmp += s[i][select_tablename_index];
                select_tablename_index++;
            }
            if (select_syntax_tmp != select_syntax_validation[0]) {
                cout << "!!!!!! Syntax ERROR S!!!!!!!!" << endl;
                return;
            }
            while (s[i][select_tablename_index] == ' ')
                select_tablename_index++;
            if (s[i][select_tablename_index] == '*') {
                select_tablename_index++;
                while (s[i][select_tablename_index] == ' ')
                    select_tablename_index++;
                select_syntax_tmp = "";
                while (s[i][select_tablename_index] != ' ') {
                    select_syntax_tmp += s[i][select_tablename_index];
                    select_tablename_index++;
                }
                if (select_syntax_tmp != select_syntax_validation[1]) {
                    cout << "!!!!!! Syntax ERROR S!!!!!!!!" << endl;
                    return;
                }
                while (s[i][select_tablename_index] == ' ')
                    select_tablename_index++;
                while (s[i][select_tablename_index] != ' ') {
                    select_tablename += s[i][select_tablename_index];
                    select_tablename_index++;
                }

                for (int j = 0; j < table_numbers; ++j) {
                    if (tables[j].name == select_tablename) {
                        tables[j].select(s[i]);
                        break;
                    }
                }
            } else if (s[i][select_tablename_index] == '(') {
                while (s[i][select_tablename_index] != ')') {
                    select_tablename_index++;
                    if (select_tablename_index == s[i].length()) {
                        cout << "!!!!!!! Syntax ERROR S!!!!!!!!" << endl;
                        return;
                    }
                }
                select_tablename_index++;
                while (s[i][select_tablename_index] == ' ')
                    select_tablename_index++;
                select_syntax_tmp = "";
                while (s[i][select_tablename_index] != ' ') {
                    select_syntax_tmp += s[i][select_tablename_index];
                    select_tablename_index++;
                }
                if (select_syntax_tmp != select_syntax_validation[1]) {
                    cout << "!!!!!!!! Syntax ERROR S!!!!!!!!!" << endl;
                    return;
                }
                while (s[i][select_tablename_index] == ' ')
                    select_tablename_index++;
                while (s[i][select_tablename_index] != ' ') {
                    select_tablename += s[i][select_tablename_index];
                    select_tablename_index++;
                }
                for (int j = 0; j < table_numbers; ++j) {
                    if (tables[j].name == select_tablename) {
                        tables[j].select(s[i]);
                        break;
                    }
                }
            } else {
                cout << "!!!!!! Syntax ERROR S!!!!!!!!" << endl;
                return;
            }
        }
    }
}
int main() {
    int n, table_numbers = 0, table_queries_index = 0;
    cin>>n;
    string s[n];
    cin.ignore();
    for (int i = 0; i < n; ++i){
        getline(cin, s[i]);
        if(s[i][0] == 'C')
            table_numbers++;
    }
    string create_queries[table_numbers];
    for (int i = 0; i < n; ++i) {
        if(s[i][0] == 'C') {
            create_queries[table_queries_index] = s[i];
            table_queries_index++;
        }
    }
    handler(s,n,table_numbers, create_queries);
}

/*
 * CREATE TABLE student (name string, score int, date timestamp)
 * CREATE TABLE teacher (name string, course string, age int)
 * INSERT INTO student VALUES ("Arman", 13, 2001/5/6)
 * INSERT INTO student VALUES ("Arash", 15, 2010/10/12)
 * INSERT INTO student VALUES ("Mohammad", 17, 2020/5/20)
 * INSERT INTO student VALUES ("Narges", 20, 2022/5/2)
 * INSERT INTO teacher VALUES ("Bagher", DS, 50)
 * INSERT INTO teacher VALUES ("Abbas", AP, 48)
 * INSERT INTO teacher VALUES ("Hedye", DM, 39)
 * SELECT * FROM student WHERE score>10
 * SELECT * FROM teacher WHERE age<100
 */
/*
21
CREATE TABLE student (name string, score int, date timestamp)
CREATE TABLE teacher (name string, course string, age int)
INSERT INTO student VALUES ("arman", 13, 2001/5/6)
INSERT INTO student VALUES ("arman", 16, 2001/5/6)
INSERT INTO student VALUES ("arman", 17, 2201/12/12)
INSERT INTO student VALUES ("arman", 20, 2001/5/6)
INSERT INTO student VALUES ("arash", 15, 2010/10/12)
INSERT INTO student VALUES ("maohammad", 17, 2020/5/20)
INSERT INTO student VALUES ("narges", 20, 2022/5/2)
INSERT INTO teacher VALUES ("bagher", ds, 50)
INSERT INTO teacher VALUES ("abbas", ap, 48)
INSERT INTO teacher VALUES ("abbas", ap, 48)
INSERT INTO teacher VALUES ("abbas", ap, 48)
INSERT INTO teacher VALUES ("hedye", dm, 39)
SELECT * FROM student WHERE score>10
SELECT * FROM teacher WHERE age<100
DELETE FROM student WHERE score==20
DELETE FROM teacher WHERE age<40
UPDATE student SET ("Gee", 21, 2002/3/8) WHERE name=="arman"
SELECT * FROM student WHERE score>10
SELECT * FROM teacher WHERE age<100
 */