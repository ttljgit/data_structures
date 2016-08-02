//邻接表存储 无权图的单源最短路算法
//dist[]和path[]全部初始化为-1
void Unweighted(LGraph Graph, int dist[], int path[], Vertex S)
{
	Queue Q;
	Vertex V;
	PtrToAdjVNode W;
	
	Q = CreateQueue(Graph->Nv);		//创建空队列，MaxSize为外部定义的常数 
	dist[S] = 0;	//初始化原点
	AddQ(Q, S);
	
	while (!IsEmpty(Q)){
		V = Delete(Q);
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)		//对V的每个邻接点W->AdjV
			if(dist[W->Adj] == -1){		//若W-Adj未被访问过 
				dist[W->Adj] = dist[V] + 1;	//W->AdjV到S的距离更新
				path[W->Adj] = V;	//将Vj记录在S到W->AdjV的路径上
				Add(Q, W->AdjV); 
			}	 
	}	
} 

//邻接矩阵储存，有权图的单源最短路算法
//返回未被收录顶点中dist最小者
Vertex FindMinDist(MGraph Graph, int dist[], int cellected[])
{
	Vertex MinV, V;
	int MinDist = INIFINITY;
	
	for(V = 0; V < Graph->Nv; V++){
		if(collected[V] == false && dist[V] < MinDist){
			//若V为被收录。且dist[V]更小
			MinDist = dist[V];	//更新最小距离
			MinV = V;	//更新对应顶点 
		}
	}	
	//若找到最小dist，返回对应的顶点下标 
	if (MinDist < INIFINITY)	 
		return MinV;
	else
		return ERROR;	
} 
bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;
	
	//初始化：此处默认邻接矩阵中不存在的边用INIFINITY表示
	for (V = 0; V < Graph->Nv; V++){
		dist[V] = Graph->G[S][V];
		path[V] = -1;
		collected[V] = false;
	} 
	//先将起点收入集合
	dist[S] = 0;
	collected[S] = true;
	
	while(1){
		//V = 未被收录顶点中dist最小者
		V = FinMinDist(Graph, dist, collected);
		if (V == ERROR)
			break;
		collected[V] = true;	//收录V
		for (W = 0; W < Graph->Nv; W++)	//对图中每个顶点W
			//若W是V的顶点并且未被收录 
			if(collected[W] == false && Graph->G[V][W] < INIFINITY){
				if(Graph->G[V][W] < 0)
					return false;	//若有负边，不能正确解决，返回错误标记 			
				//若收录V使得dist[W]变小 
				if(dist[V]+Graph->G[V][W] < dist[W]){
					dist[W] = dist[V]+Graph->G[V][W];	//更新dist[W]
					path[W] = V;	//更新S到W的路径 
				}
		}
	} 
	return true; 
}

//邻接矩阵存储 多源最短算法
bool Floyed(MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[MaxVertexNum])
{
	Vertex i, j, k;
	
	//初始化
	for(i = 0; i < Graph->Nv; i++){
		for(j = 0; j < Graph->Nv; j++){
			D[i][j] = Graph->G[i][j];
			path[i][j] = -1;
		}
	}
		
	for(k = 0; k < Graph->Nv; k++)
		for(i = 0; i < Graph->Nv; i++)
			for(j= 0; j < Graph->Nv; j++)
				if(D[i][j] + D[k][j] < D[i][j]){
					//若发现负圈，不能正确解决，返回错误标记 
					if(i == j && D[i][j] < 0)
						return false;
					path[i][j] = k;	
				}
	return true;			
} 
