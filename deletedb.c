#include <mysql.h>
#include <my_global.h>
#include <stdio.h>

void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);        
}

main() {
   MYSQL *conn = mysql_init(NULL);

    if (conn == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(conn, "localhost", "root", "x94u4cl6", "mysql", 0, NULL, 0) == NULL)
	{
    	finish_with_error(conn);
    }    
  
   MYSQL_ROW row;
   //conn = mysql_init(NULL);
   /* Connect to database */
   /* send SQL query */
   /* close connection */ 

   //if (mysql_query(conn, "DELETE FROM USER_inform WHERE id=")) 
   
   if (mysql_query(conn, "DROP TABLE IF EXISTS columns_priv "))
   {
      finish_with_error(conn);
   }
   if (mysql_query(conn, "DROP TABLE IF EXISTS db"))
   {
   	finish_with_error(conn);
   }
   if (mysql_query(conn, "DROP TABLE IF EXISTS event"))
   {
        finish_with_error(conn);
   }
   if (mysql_query(conn, "DROP TABLE IF EXISTS func"))
   {
        finish_with_error(conn);
   }
   if (mysql_query(conn, "DROP TABLE IF EXISTS general_log "))
   {
        finish_with_error(conn);
   }
   mysql_query(conn, "DROP TABLE IF EXISTS help_category ");
   mysql_query(conn, "DROP TABLE IF EXISTS help_keyword");
   mysql_query(conn, "DROP TABLE IF EXISTS help_relation");
   mysql_query(conn, "DROP TABLE IF EXISTS help_topic");
   mysql_query(conn, "DROP TABLE IF EXISTS host");
   mysql_query(conn, "DROP TABLE IF EXISTS ndb_binlog_index ");
   mysql_query(conn, "DROP TABLE IF EXISTS plugin");
   mysql_query(conn, "DROP TABLE IF EXISTS proc ");
   mysql_query(conn, "DROP TABLE IF EXISTS procs_priv");
   mysql_query(conn, "DROP TABLE IF EXISTS proxies_priv ");
   mysql_query(conn, "DROP TABLE IF EXISTS servers ");
   mysql_query(conn, "DROP TABLE IF EXISTS slow_log");
   mysql_query(conn, "DROP TABLE IF EXISTS tables_priv");
   mysql_query(conn, "DROP TABLE IF EXISTS time_zone ");
   mysql_query(conn, "DROP TABLE IF EXISTS time_zone_leap_second");
   mysql_query(conn, "DROP TABLE IF EXISTS time_zone_name");
   mysql_query(conn, "DROP TABLE IF EXISTS time_zone_transition");
   mysql_query(conn, "DROP TABLE IF EXISTS time_zone_transition_type");
   mysql_query(conn, "DROP TABLE IF EXISTS user ");


   //if (mysql_query(conn, "INSERT INTO authen VALUES('RLai')")) {
     //  finish_with_error(conn);
//	}


 /* if (mysql_query(conn, "INSERT INTO USER_inform VALUES('RLai','monmon','rlai@mail')")) {
      finish_with_error(conn);
  }
if (mysql_query(conn, "INSERT INTO USER_inform VALUES('monmon','love','mon@mail')")) {
      finish_with_error(conn);
  }*/
   mysql_close(conn);
}
