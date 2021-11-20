#include <mysql.h>
#include <stdio.h>

int main(void)
{
    printf("Content-type: text/html\n\n");
    printf("<html><title>Hello</title>\n");
    printf("<style>td{ font-family: Comic Sans MS; border: 1px solid black; }</style><body>\n");
    printf("Goodbye Cruel World\n");
    printf("</body></html>");

    MYSQL *con = mysql_init(NULL);
    printf("MySQL client version: %s<br>", mysql_get_client_info());

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "webuser", "secretpassword",
                           "Opdracht3", 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    
    shtable(con);
    
}

int shtable(con)
{
    if (mysql_query(con, "SELECT * FROM state"))
    {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    MYSQL_FIELD *field;

    printf("<table>\n");
    
    while ((row = mysql_fetch_row(result)))
    {
        printf("\n");
        for (int i = 0; i < num_fields; i++)
        {
            if (i == 0)
            {
                while (field = mysql_fetch_field(result))
                {
                    printf("<th>%s ", field->name);
                }
                printf("<tr>\n");
            }
            printf("<td>%s  ", row[i] ? row[i] : "NULL");
        }
    }

    printf("\n");

    mysql_free_result(result);
    mysql_close(con);
}

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}