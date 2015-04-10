#include <iostream>       // std::cout
#include <limits>
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
#include <set>

struct Node{
  int        x;
  int        y;
  int        cost;
  Node operator+(const Node& n1) const
  {
    Node sum;
    sum.x = x + n1.x;
    sum.y = y + n1.y;
    sum.cost = cost + n1.cost;
    return sum;
  }
  int operator-(const Node& n1) const
  {
    int sum;
    if(x>n1.x)
      sum = x - n1.x;
    else
      sum = n1.x - x;
    if(y>n1.y)
      sum += y - n1.y;
    else
      sum += n1.y - y;
    return sum;
  }
  bool operator==(const Node& n1) const
  {
    return (x == n1.x && y == n1.y);
  }
};

class CostComp
{
public:
  bool operator() (const Node& lhs, const Node&rhs) const
  {
    return (lhs.cost>rhs.cost);
  }
};

class NodeComp
{
public:
  bool operator() (const Node& lhs, const Node&rhs) const
  {
    if(lhs.x == rhs.x)
      return (lhs.y<rhs.y);
    else
      return (lhs.x<rhs.x);
  }
};

class Orienteering
{
  bool** M_;
  int m_, n_;
  Node start_;
  Node goal_;
  std::vector<Node> cps_;
  public:
    void main();
    int min_distance(Node start, Node goal); 
    int tsp(int n, std::vector< std::vector<int> >& cost);
};

void Orienteering::main()
{
  std::cin >> n_; std::cin >> m_;
  M_ = new bool*[m_];
  for(int i=0; i<m_; i++)
    M_[i] = new bool[n_];
  for(int i=0; i<m_; i++)
    for(int j=0; j<n_; j++)
    {
      char a;
      std::cin >> a;
      if(a == '.')
        M_[i][j] = true;
      if(a == '#')
        M_[i][j] = false;
      if(a == '@')
      {
        M_[i][j] = true;
        Node node; node.x = i; node.y = j;
        cps_.push_back(node);
      }
      if(a == 'S')
      {
        M_[i][j] = true;
        start_.x = i; start_.y = j;
      }
      if(a == 'G')
      {
        M_[i][j] = true;
        goal_.x = i; goal_.y = j;
      }
    }
  //for(int i=0;i<m_;i++)
  //{
    //for(int j=0;j<n_;j++)
    //{
      //std::cout << M_[i][j];
    //}
    //std::cout << std::endl;
  //}

  cps_.insert(cps_.begin(), start_);
  cps_.push_back(goal_);
  int cps_count = cps_.size();
  std::vector< std::vector<int> > cost(cps_count, std::vector<int>(cps_count));
  for(int i=0; i<cps_count; i++)
    for(int j=i; j<cps_count; j++)
    {
      if(i == j)
      {
        cost[i][j] = 0;
        continue;
      }
      int distance = min_distance(cps_.at(i), cps_.at(j));
      cost[i][j] = distance;
      cost[j][i] = distance;
    }
  std::cout << tsp(cps_count-1, cost) << std::endl;
}

int Orienteering::tsp(int n, std::vector< std::vector<int> >& cost)
{
  //std::cout << "enter tsp" << std::endl;
  if(n==1)
    return cost[0][1];
  long nsub = 1 << n;
  std::vector < std::vector<int> > opt(nsub, std::vector<int>(n));
  opt[1][0] = 0;
  for (long s = 3; s < nsub; s += 2)
    for (int i = 1; i < n; ++i) {
      std::vector<int> subset;
      for (int u = 0; u < n; ++u)
        if (s & (1 << u))
          subset.push_back(u);
      if (((s & (1 << i)) == 0))
        opt[s][i] = std::numeric_limits<int>::max();
      else if (subset.size() == 2)
        opt[s][i] = cost[0][i];
      else if (subset.size() > 2 && ((s & (1 << i)) > 1)) {
        int min_subpath = std::numeric_limits<int>::max();
        long t = s & ~(1 << i);
        for (std::vector<int>::iterator j = ++subset.begin(); j != subset.end(); ++j)
          if (*j != i && opt[t][*j] + cost[*j][i] < min_subpath)
          {
            //std::cout << t << "   " << *j << "   " << opt[t][*j] << cost[*j][i]<< std::endl;
            min_subpath = opt[t][*j] + cost[*j][i];
          }
        opt[s][i] = min_subpath;
      }
      //std::cout << s << "   " << i << "   " << opt[s][i] << std::endl;
    }
  long s = nsub - 1;
  //std::cout << s << std::endl;
  int min_path = std::numeric_limits<int>::max();
  for (int i = 1; i < n; ++i) {
    if(opt[s][i]+cost[i][n] < min_path)
    {
      //std::cout << i << "    " << opt[s][i] << "    " << cost[i][n] << std::endl;
      min_path = opt[s][i] + cost[i][n];
    }
  }
  return min_path;
}

int Orienteering::min_distance(Node start, Node goal)
{
  //std::cout << "start min_instance" << std::endl;
  std::set<Node, NodeComp> closed;
  std::set<Node, NodeComp> openset;
  std::priority_queue<Node,std::vector<Node>,CostComp> open;
  start.cost = goal-start;
  open.push(start);
  openset.insert(start);
  while(!open.empty())
  {
    Node current = open.top();
    //std::cout << current.cost << "    "  << current.x << "    " << current.y << "    "  << std::endl;
    if(current == goal)
    {
      //std::cout << "end min_instance" << std::endl;
      return current.cost;
    }
    else
    {
      open.pop();
      closed.insert(current);
      Node nbrs[4]; //TODO make func for neighbours
      nbrs[0].x = current.x;nbrs[0].y = current.y-1;
      nbrs[0].cost = (current.cost+1)-(current-goal);
      nbrs[0].cost += nbrs[0] - goal;
      nbrs[1].x = current.x;nbrs[1].y = current.y+1;
      nbrs[1].cost = (current.cost+1)-(current-goal);
      nbrs[1].cost += nbrs[1] - goal;
      nbrs[2].x = current.x-1;nbrs[2].y = current.y;
      nbrs[2].cost = (current.cost+1)-(current-goal);
      nbrs[2].cost += nbrs[2] - goal;
      nbrs[3].x = current.x+1;nbrs[3].y = current.y;
      nbrs[3].cost = (current.cost+1)-(current-goal);
      nbrs[3].cost += nbrs[3] - goal;
      for (int j=0; j<4; j++)
      {
        if(nbrs[j].x<0 || nbrs[j].y<0 || nbrs[j].x>=m_ || nbrs[j].y>=n_ || !M_[nbrs[j].x][nbrs[j].y])
          continue;
        if(closed.find(nbrs[j])!=closed.end())
        {
          continue;
        }
        std::set<Node>::iterator it = openset.find(nbrs[j]);
        if(it==openset.end())
        {
          openset.insert(nbrs[j]);
          open.push(nbrs[j]);
        }
        else
        {
          Node element = *it;
          if(element.cost>nbrs[j].cost)
          {
            openset.erase(it);
            openset.insert(nbrs[j]);
            open.push(nbrs[j]);
          }
        }
      }
    }
  }
  return -1;
}

int main(int argc, char* argv[])
{
  Orienteering o;
  o.main();
  return 0;
}
