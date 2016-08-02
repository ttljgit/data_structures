//邻接矩阵存储 Prim最小生成树算法

//返回未被收顶点中dist最小者
Vertex FindMinDist(MGraph Graph, WeightType dits[])
{
	Vertex MinV, V;
	WeightType MinDist = INIFINITY;
	
	for(V = 0; V < Graph->Nv; V++){
		//若V未被收录，且dist[V]更小 
		if(dist[V] != 0 && dist[V] < MinDist){
			MinDist = dist[V];	//更新最小距离 
			MinV = V; 	//更新对应顶点 
	}	
	//若未找到最小dist,返回对应的顶点下标，若这样的顶点不存在，返回-1 
	if(MinDist < INIFINITY)
		return MinV; 
	else return ERROR;	
} 

//将最小生成树保存为邻接表存储的图 MST，返回最小权重和
int Prim(MGraph Graph, LGraph MST)
{
	WeightType dist[MaxVertexNum], TotalWeight;
	Vertex parent[MaxVertexNum], V, W;
	int VCount;
	Edge E;
	
	//初始化：默认初始点下标是0
	for(V = 0; V < Graph->Nv; V++){
		//这里假设若V到W没有直接的边，则Graph->G[V][W]定义为IFINITY
		dist[V] = Graph->G[0][V];
		parent[V] = 0;	//暂且定义所有顶点的父节点都是初始点0 
	}	
	TotalWeight = 0;
	VCount = 0;	
	MST = CreateGraph(Graph->Nv);
	E = (Edge)malloc(sizeof(struct ENode));
	
	//将初始点0收录进MST
	dist[0] = 0;
	VCount++;
	parent[0] = -1;	//当前树根是0 
	
	while (1){
		V = FindMinDist(Graph, dist);
		//V = 未被收录顶点中dist最小者
		if (V ==ERROR)
			break;
		//将V及相应的边<parent[V], V>收录进MST
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(MST, E);
		TotalWeight += dist[V];
		dist[V] = 0;
		VCount++;
		
		for(W = 0; W < Graph->Nv; W++){
			//若W是V的邻接点并且未被收录
			if(dist[W] != 0 && Graph->G[V][W] < INFINITY){ 
				//若收录V使得dist[W]变小 
				if(Graph->G[V][W] < dist[W]){
					dist[W] = Graph->G[V][W];
					parent[W] = V; 
				} 
			}
		}	 
	}
	//MST中收录的顶点若不到V个 
	if(VCount < Graph->Nv)
		TotalWeight = ERROR;
	return TotalWeight;	
} 
