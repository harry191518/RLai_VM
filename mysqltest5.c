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
	mysql_query(conn, "delete from USER_inform where id='a1'"); 
	mysql_query(conn, "delete from USER_inform where id='a2'");
	mysql_query(conn, "delete from USER_inform where id='a3'");
	mysql_query(conn, "delete from USER_inform where id='b'");
	mysql_query(conn, "delete from USER_inform where id='c'");
	mysql_query(conn, "delete from USER_inform where id='d'");
   /*
   if (mysql_query(conn, "DROP TABLE IF EXISTS columns_priv"))
   {
      finish_with_error(conn);
   }
   if (mysql_query(conn, "DROP TABLE IF EXISTS event"))
   {
      finish_with_error(conn);
   }
   if (mysql_query(conn, "DROP TABLE IF EXISTS func "))
   {
   	finish_with_error(conn);
   }*/
   //if (mysql_query(conn, "INSERT INTO authen VALUES('RLai')")) {
     //  finish_with_error(conn);
//	}


 /* if (mysql_query(conn, "INSERT INTO USER_inform VALUES('RLai','monmon','rlai@mail')")) {
      finish_with_error(conn);
  }
if (mysql_query(conn, "INSERT INTO USER_inform VALUES('monmon','love','mon@mail')")) {
      finish_with_error(conn);
  }*/
  /*MYSQL_RES *result = mysql_store_result(conn);
  
  if (result == NULL) 
  {
      finish_with_error(conn);
  }

  int num_fields = mysql_num_fields(result);
  int i;

  while ((row = mysql_fetch_row(result))) 
  { 
      for(i = 0; i < num_fields; i++) 
      { 
          printf("%s ", row[i]); 
      } 
          printf("\n"); 
  }
   mysql_free_result(result);*/
   mysql_close(conn);
}
