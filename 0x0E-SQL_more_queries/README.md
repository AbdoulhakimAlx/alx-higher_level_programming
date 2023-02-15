# 0x0E. SQL - More queries
```
SQL
MySQL
```

# More Info

## Comments for your SQL file:
```
$ cat my_script.sql
-- 3 first students in the Batch ID=3
-- because Batch 3 is the best!
SELECT id, name FROM students WHERE batch_id = 3 ORDER BY created_at DESC LIMIT 3;
$
```

## Install MySQL 8.0 on Ubuntu 20.04 LTS

```
$ sudo apt update
$ sudo apt install mysql-server
...
$ mysql --version
mysql  Ver 8.0.25-0ubuntu0.20.04.1 for Linux on x86_64 ((Ubuntu))
$
```

Connect to your MySQL server:

```
$ sudo mysql
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 11
Server version: 8.0.25-0ubuntu0.20.04.1 (Ubuntu)

Copyright (c) 2000, 2021, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql>
mysql> quit
Bye
$
```

## Use “container-on-demand” to run MySQL

**In the container, credentials are root/root**

+ Ask for container Ubuntu 20.04
+ Connect via SSH
+ OR connect via the Web terminal
+ In the container, you should start MySQL before playing with it:

```
$ service mysql start                                                   
 * Starting MySQL database server mysqld 
$
$ cat 0-list_databases.sql | mysql -uroot -p                               
Database                                                                                   
information_schema                                                                         
mysql                                                                                      
performance_schema                                                                         
sys                      
$
```

In the container, credentials are root/root

## How to import a SQL dump

```
$ echo "CREATE DATABASE hbtn_0d_tvshows;" | mysql -uroot -p
Enter password: 
$ curl "https://s3.amazonaws.com/intranet-projects-files/holbertonschool-higher-level_programming+/274/hbtn_0d_tvshows.sql" -s | mysql -uroot -p hbtn_0d_tvshows
Enter password: 
$ echo "SELECT * FROM tv_genres" | mysql -uroot -p hbtn_0d_tvshows
Enter password: 
id  name
1   Drama
2   Mystery
3   Adventure
4   Fantasy
5   Comedy
6   Crime
7   Suspense
8   Thriller
$
```



# SQL - More queries

In this project, I continued to practicing SQL queries, working with
permissoins, joins, and constraints.

## Usage :dolphin:

* Scripts [3-force_name.sql](./3-force_name.sql) forward take the database to query from
as a MySQL command line argument.

```
$ cat 3-force_name.sql | mysql -hlocalhost -uroot -p hbtn_0d_2
```

* Tasks 3-101 query from the database [hbtn_0d_tvshows.sql](./hbtn_0d_tvshows.sql`).
* Tasks 102-103 query from the database [hbtn_0d_tvshows_rate.sql](./hbtn_0d_tvshows_rate.sql).

## Tasks :page_with_curl:

* **0. My privileges!**
  * [0-privileges.sql](./0-privileges.sql): MySQL script that lists all privileges of the users
  `user_0d_1` and `user_0d_2`.

* **1. Root user**
  * [1-create_user.sql](./1-create_user.sql): MySQL script that creates the user `user_0d_1` with
  all privileges and password `user_0d_1_pwd`.

* **2. Read user**
  * [2-create_read_user.sql](./2-create_read_user.sql): MySQL script that creates the database
  `hbtn_0d_2` and user `user_0d_2` with password `user_0d_2_pwd`.
  * `user_0d_2` only has SELECT privilege on the database `hbtn_0d_2`.

* **3. Always a name**
  * [3-force_name.sql](./3-force_name.sql): MySQL script that creates the table `force_name`.
  * Description:
    * `id`: INT
    * `name`: VARCHAR(256) (cannot be null)

* **4. ID can't be null**
  * [4-never_empty.sql](./4-never_empty.sql): MySQL script that creates the table `id_not_null`.
  * Description:
    * `id`: INT (default value = 1)
    * `name`: VARCHAR(256)

* **5. Unique ID**
  * [5-unique_id.sql](./5-unique_id.sql): MySQL script that creates the table `unique_id`.
  * Description:
    * `id`: INT (default value = 1, must be unique)
    * `name`: VARCHAR(256)

* **6. States table**
  * [6-states.sql](./6-states.sql): MySQL script that creates the database `hbtn_0d_usa`
  with a table `states`.
  * `states` description:
    * `id`: INT (unique, auto-generated, cannot be null and is a primary key)
    * `name`: VARCHAR(256) (cannot be null)

* **7. Cities table**
  * [7-cities.sql](./7-cities.sql): MySQL script that creates the database `hbtn_0d_usa`
  with a table `cities`.
  * `cities` description:
    * `id`: INT (unique, auto-generated, cannot be null and is a primary key)
    * `state_id`: INT (cannot be null, foreign key that references to id of the
    `states` table)
    * `name`: VARCHAR(256) (cannot be null)

* **8. Cities of California**
  * [8-cities_of_california_subquery.sql](./8-cities_of_california_subquery.sql):
  MySQL script that lists all the cities of California that can be found in the
  database `hbtn_0d_usa`, ordered by ascending city id.

* **9. Cities by States**
  * [9-cities_by_state_join.sql](./9-cities_by_state_join.sql): MySQL script that lists
  all cities contained in the database `hbtn_0d_usa`, ordered by ascending city id.

* **10. Genre ID by show**
  * [10-genre_id_by_show.sql](./10-genre_id_by_show.sql): MySQL script that lists all
  shows contained in `hbtn_0d_tvshows` that have at least one genre linked, in order of ascending
`tv_shows.title` and `tv_show_genres.genre_id`.

* **11. Genre ID for all shows**
  * [11-genre_id_all_shows.sql](./11-genre_id_all_shows.sql): MySQL script that lists all shows contained
  in the database `hbtn_0d_tvshows`, in order of ascending `tv_shows.title` and `tv_show_genres.genre_id`.
  * If a show does not have a genre, displays `NULL`.

* **12. No genre**
  * [12-no_genre.sql](./12-no_genre.sql): MySQL script that lists all shows contained in
  `hbtn_0d_tvshows` without a genre linked, in order of ascending `tv_shows.title` and `tv_show_genres.genre_id`.

* **13. Number of shows by genre**
  * [13-count_shows_by_genre.sql](./13-count_shows_by_genre.sql): MySQL script that lists all genres from
  `hbtn_0d_tvshows` and displays the number of shows linked to each, in order of descending number of shows linked.
  * Does not display a genre if it has no linked shows.

* **14. My genres**
  * [14-my_genres.sql](./14-my_genres.sql): MySQL script that uses the `hbtn_0d_tvshows` database
  to list all genres of the show Dexter, in order of ascending genre name.

* **15. Only Comedy**
  * [15-comedy_only.sql](./15-comedy_only.sql): MySQL script that lists all comedy shows in the
  database `hbtn_0d_tvshows`, in order of ascending show title.

* **16. List shows and genres**
  * [16-shows_by_genre.sql](./16-shows_by_genre.sql): MySQL script that lists all shows, and all genres
  linked to that show, from the database `hbtn_0d_tvshows`, in order of ascending show title and genre name.

* **17. Not my genre**
  * [100-not_my_genres.sql](./100-not_my_genres.sql`) MySQL script that uses the `hbtn_0d_tvshows`
  database to list all genres not linked to the show Dexter, in order of ascending genre name.

* **18. No Comedy tonight!**
  * [101-not_a_comedy.sql](./101-not_a_comedy.sql): MySQL script that lists all shows without the
  genre comedy in the database `hbtn_0d_tvshows`, in order of ascending show title.

* **19. Rotten tomatoes**
  * [102-rating_shows.sql](./102-rating_shows.sql): MySQL script that lists all shows from
  `hbtn_0d_tvshows_rate` by their rating, in order of descending rating.

* **20. Best genre**
  * [103-rating_genres.sql](./103-rating_genres.sql): MySQL script that lists all genres in the
  database `hbtn_0d_tvshows_rate` by their rating, in order of descending rating.

## author
Bouari abdoul hakim
