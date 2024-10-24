/*
 * Created By Ron Potashnik 2024.
 */

#include <stdio.h>
#include <signal.h>

/* Define the size of the matrix */
#define N 10

/* Define a boolean type */
typedef enum BOOL_E
{
    FALSE = 0,
    TRUE = 1
} BOOL_E;

/* Define the adjacency matrix type */
typedef short Adjmat[N][N];
typedef const short (*Const_Adjmat)[N];

/*
    @brief Check if there is a path from u to v int the graph
    @param mat The adjacency matrix of the graph
    @param u The parent vertex
    @param v The child vertex
    @return TRUE if there is a path from u to v, FALSE otherwise
*/
static BOOL_E path(Const_Adjmat mat, int u, int v);

/*
    @brief Helper function to check if there is a path from u to v int the graph
    @param mat The adjacency matrix of the graph
    @param u The parent vertex
    @param v The child vertex
    @param visited The visited vertices
    @return TRUE if there is a path from u to v, FALSE otherwise
*/
static BOOL_E path_util(Const_Adjmat mat, int u, int v, BOOL_E visited[N]);

/*
    @brief Print the adjacency matrix
    @param mat The adjacency matrix of the graph
*/
static void adjmat_print(Const_Adjmat mat);

/*
    @brief Signal handler for SIGINT
    @param sig_num The signal number
*/
static void sigint_handler(int sig_num);

/*
    @brief Signal handler for SIGTSTP
    @param sig_num The signal number
*/
static void sigtstp_handler(int sig_num);

int main()
{
    Adjmat adj_mat;
    int u, v;

    printf("Please Enter the adjacency matrix (%d x %d):\n", N, N);
    printf ("if u and v have a direct edge between them, enter 1, otherwise enter 0\n");

    /* Read the adjacency matrix */
    for (u = 0; u < N; ++u)
    {
        for (v = 0; v < N; ++v)
        {
            printf("Please enter the value of A[%d][%d]:\n", u, v);
            scanf("%hd", &adj_mat[u][v]);
        }
    }

    adjmat_print((Const_Adjmat)adj_mat);

    /* Register the signal handler for SIGINT and SIGTSTP */
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, sigtstp_handler);

    while (1)
    {
        printf("Please enter u and v to check if there is a path from u to v:\n");
        printf("Enter -1, -1 to exit\n");
        scanf("%d %d", &u, &v);

        if (u == -1 && v == -1)
        {
            break;
        }

        if (path((Const_Adjmat)adj_mat, u, v))
        {
            printf("There is a path from %d to %d\n", u, v);
        }
        else
        {
            printf("There is no path from %d to %d\n", u, v);
        }
    }

    return 0;
}

static BOOL_E path_util(Const_Adjmat mat, int u, int v, BOOL_E visited[N])
{
    int i;

    /* Check if the vertices are valid */
    if (u < 0 || u >= N || v < 0 || v >= N)
    {
        return FALSE;
    }

    /* Mark current vertex as visited */
    visited[u] = TRUE;

    /* If we found direct path or reached destination */
    if (u == v || mat[u][v] == 1)
    {
        return TRUE;
    }

    /* Check path through other vertices */
    for (i = 0; i < N; ++i)
    {
        if (!visited[i] && mat[u][i] == 1)
        {
            if (path_util(mat, i, v, visited))
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

static BOOL_E path(Const_Adjmat mat, int u, int v)
{
    /* Initialize visited array */
    BOOL_E visited[N] = {FALSE};

    return path_util(mat, u, v, visited);
}

static void adjmat_print(Const_Adjmat mat)
{
    int i, j;

    printf("The adjacency matrix is:\n");

    /* Print the column numbers */
    printf("      ");
    for (j = 0; j < N; ++j)
    {
        printf("%4d", j);
    }
    printf("\n");

    /* Print the horizontal line */
    printf("    ");
    for (j = 0; j < N; ++j)
    {
        printf("-----");
    }
    printf("\n");

    /* Print the matrix */
    for (i = 0; i < N; ++i)
    {
        printf("%4d |", i);

        for (j = 0; j < N; ++j)
        {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

static void sigint_handler(int sig_num)
{
    signal(SIGINT, SIG_IGN);
    printf("\nReceived SIGINT (Ctrl + C). Ignoring the signal. You can only exit by entering -1, -1\n");
    fflush(stdout);  /* Flush the output to ensure the message is printed */
}

static void sigtstp_handler(int sig_num)
{
    signal(SIGTSTP, SIG_IGN);
    printf("\nReceived SIGTSTP (Ctrl + Z). Ignoring the signal. You can only exit by entering -1, -1\n");
    fflush(stdout);
}