#include <bits/stdc++.h>

using namespace std ;

int dx[]= {0,0,1,-1};/*4 side move*/
int dy[]= {-1,1,0,0};/*4 side move*/


vector< vector< pair<int,int> > > all_path ;
vector< pair<int,int> > v ;
vector<int>path_robot[200] ;
vector<int>robot_path[10] ;

bool flag[20][20] ;
int n , m , d_x , d_y , mnm ;
clock_t path_time[200] ;
bool first_path[200] ;
int path_u[200] ;

ofstream robot1out ("robotAnalyst.txt");
ifstream robot1in ("robotAnalyst.txt");
ofstream robot2out ("robotmovementhistory.txt");
ifstream robot2in ("robotmovementhistory.txt");

void cal_path(int x,int y)
{
    if(x == d_x and y == d_y)
    {
        //printf("%d %d %d\n",x,y,v.size());
        all_path.push_back(v);
        mnm = min(mnm,(int)v.size());
        return ;
    }

    for(int i=0 ; i<4 ; i++)
    {
        int t_x = x + dx[i] , t_y = y + dy[i] ;

        if(t_x>=0 and t_x<n and t_y>=0 and t_y<m and !flag[t_x][t_y])
        {
            flag[t_x][t_y] = 1 ;
            v.push_back(make_pair(t_x,t_y));
            cal_path(t_x,t_y);
            flag[t_x][t_y] = 0 ;
            v.pop_back();
        }
    }
}

double prif(int pth)
{
    int tp = all_path[pth-1].size() ;
    double ans = (double)mnm/(double)tp ;
    ans = ans*100.0 ;
    return ans ;
}

int main()
{
    n = 4 ;
    m = 4 ;

    while(1)
    {
        int option ;

        printf("Option 1: Play\n");
        printf("Option 2: Robot Analyst\n");
        printf("Option 3: exit\n");

        printf("Select Your Option: ");
        scanf("%d",&option);

        if(option == 3)
            break ;

        if(option == 1)
        {
            int s_x , s_y ;

            all_path.clear();
            v.clear();
            memset(path_u,0,sizeof(path_u));

            mnm = 100 ;

            printf("Select Your Starting Point: ");
            scanf("%d %d",&s_x,&s_y);
            printf("Select Your Ending Point: ");
            scanf("%d %d",&d_x,&d_y);

            flag[s_x][s_y] = 1 ;
            cal_path(s_x,s_y);
//printf("%d\n",all_path.size());system("pause");
            for(int i=0 ; i<all_path.size() ; i++)
            {
                printf("PATH %d : (%d,%d)",i+1,s_x,s_y);
                for(int j=0 ; j<all_path[i].size() ; j++)
                {
                    printf(" -> (%d,%d)",all_path[i][j].first,all_path[i][j].second);
                }
                printf("\n");
                printf("Path Cost: %d\n",all_path[i].size());
            }

            while(1) // for robot 1
            {
                int pth ;
                printf("Select Your Path: ");
                scanf("%d",&pth);
                printf("Preferability: %.4f\n",prif(pth));

                robot_path[1].push_back(pth);
                path_robot[pth-1].push_back(1);

                first_path[pth] = 1 ;
                path_time[pth] = clock();

                char str[5] ;
                printf("Do You Want to Play with Same Robot Again? (Y/N) ");
                scanf("%s",str);

                if(tolower(str[0]) == 'y')
                    continue;
                break;
            }

            while(1) // for robot 2
            {
                int pth ;
                printf("Select Your Path: ");
                scanf("%d",&pth);

                if(first_path[pth] and path_u[pth] != 2)
                {
                    clock_t endd = clock();
                    double time_sp = (double)(endd - path_time[pth])/CLOCKS_PER_SEC ;

                    if(time_sp<300.0)
                    {
                        printf("This Path is engaged now !!! Please try again after %.5f second .\n",300.0-time_sp);
                        continue;
                    }
                }

                path_u[pth] = 2 ;
                first_path[pth] = 1 ;
                path_time[pth] = clock();

                printf("Preferability: %.4f\n",prif(pth));

                robot_path[2].push_back(pth);
                path_robot[pth-1].push_back(2);

                char str[5] ;
                printf("Do You Want to Play with Same Robot Again? (Y/N) ");
                scanf("%s",str);

                if(tolower(str[0]) == 'y')
                    continue;
                break;
            }

            while(1) // for robot 3
            {
                int pth ;
                printf("Select Your Path: ");
                scanf("%d",&pth);

                if(first_path[pth] and path_u[pth] != 3)
                {
                    clock_t endd = clock();
                    double time_sp = (double)(endd - path_time[pth])/CLOCKS_PER_SEC ;

                    if(time_sp<300.0)
                    {
                        printf("This Path is engaged now !!! Please try again after %.5f second .\n",300.0-time_sp);
                        continue;
                    }
                }

                path_u[pth] = 3 ;
                first_path[pth] = 1 ;
                path_time[pth] = clock();

                printf("Preferability: %.4f\n",prif(pth));

                robot_path[3].push_back(pth);
                path_robot[pth-1].push_back(3);
                //robot3out<<pth<<endl ;

                char str[5] ;
                printf("Do You Want to Play with Same Robot Again? (Y/N) ");
                scanf("%s",str);

                if(tolower(str[0]) == 'y')
                    continue;
                break;
            }

            while(1) // for robot 4
            {
                int pth ;
                printf("Select Your Path: ");
                scanf("%d",&pth);

                if(first_path[pth] and path_u[pth] != 4)
                {
                    clock_t endd = clock();
                    double time_sp = (double)(endd - path_time[pth])/CLOCKS_PER_SEC ;

                    if(time_sp<300.0)
                    {
                        printf("This Path is engaged now !!! Please try again after %.5f second .\n",300.0-time_sp);
                        continue;
                    }
                }

                path_u[pth] = 4 ;
                first_path[pth] = 1 ;
                path_time[pth] = clock();

                printf("Preferability: %.4f\n",prif(pth));

                robot_path[4].push_back(pth);
                path_robot[pth-1].push_back(4);
                //robot4out<<pth<<endl ;

                char str[5] ;
                printf("Do You Want to Play with Same Robot Again? (Y/N) ");
                scanf("%s",str);

                if(tolower(str[0]) == 'y')
                    continue;
                break;
            }
        }

        else
        {
            if(robot_path[1].size() == 0)
            {
                printf("You haven't played yet.\n");
            }

            else
            {
                robot1out<<"Robot   Path\n\n";

                for(int i=1 ; i<=4 ; i++)
                {
                    robot1out << "  " << i << "     ";

                    for(int j=0 ; j<robot_path[i].size() ; j++)
                    {
                        if(j)
                            robot1out<<",";

                        robot1out<<robot_path[i][j];
                    }
                    robot1out<<endl;
                }

                robot2out<<"Path   Robot\n\n";

                for(int i=0 ; i<185 ; i++)
                {
                    if(path_robot[i].size() != 0)
                    {
                        robot2out<<"  "<<i+1<<"      ";

                        for(int j=0 ; j<path_robot[i].size() ; j++)
                        {
                            if(j)
                                robot2out<<",";
                            robot2out<<path_robot[i][j];
                        }
                        robot2out<<endl;
                    }
                }

                printf("Analyst Completed\n");
            }
        }

    }
    return 0;
}
