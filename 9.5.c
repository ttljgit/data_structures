//�ڽӾ���洢 Prim��С�������㷨

//����δ���ն�����dist��С��
Vertex FindMinDist(MGraph Graph, WeightType dits[])
{
	Vertex MinV, V;
	WeightType MinDist = INIFINITY;
	
	for(V = 0; V < Graph->Nv; V++){
		//��Vδ����¼����dist[V]��С 
		if(dist[V] != 0 && dist[V] < MinDist){
			MinDist = dist[V];	//������С���� 
			MinV = V; 	//���¶�Ӧ���� 
	}	
	//��δ�ҵ���Сdist,���ض�Ӧ�Ķ����±꣬�������Ķ��㲻���ڣ�����-1 
	if(MinDist < INIFINITY)
		return MinV; 
	else return ERROR;	
} 

//����С����������Ϊ�ڽӱ�洢��ͼ MST��������СȨ�غ�
int Prim(MGraph Graph, LGraph MST)
{
	WeightType dist[MaxVertexNum], TotalWeight;
	Vertex parent[MaxVertexNum], V, W;
	int VCount;
	Edge E;
	
	//��ʼ����Ĭ�ϳ�ʼ���±���0
	for(V = 0; V < Graph->Nv; V++){
		//���������V��Wû��ֱ�ӵıߣ���Graph->G[V][W]����ΪIFINITY
		dist[V] = Graph->G[0][V];
		parent[V] = 0;	//���Ҷ������ж���ĸ��ڵ㶼�ǳ�ʼ��0 
	}	
	TotalWeight = 0;
	VCount = 0;	
	MST = CreateGraph(Graph->Nv);
	E = (Edge)malloc(sizeof(struct ENode));
	
	//����ʼ��0��¼��MST
	dist[0] = 0;
	VCount++;
	parent[0] = -1;	//��ǰ������0 
	
	while (1){
		V = FindMinDist(Graph, dist);
		//V = δ����¼������dist��С��
		if (V ==ERROR)
			break;
		//��V����Ӧ�ı�<parent[V], V>��¼��MST
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(MST, E);
		TotalWeight += dist[V];
		dist[V] = 0;
		VCount++;
		
		for(W = 0; W < Graph->Nv; W++){
			//��W��V���ڽӵ㲢��δ����¼
			if(dist[W] != 0 && Graph->G[V][W] < INFINITY){ 
				//����¼Vʹ��dist[W]��С 
				if(Graph->G[V][W] < dist[W]){
					dist[W] = Graph->G[V][W];
					parent[W] = V; 
				} 
			}
		}	 
	}
	//MST����¼�Ķ���������V�� 
	if(VCount < Graph->Nv)
		TotalWeight = ERROR;
	return TotalWeight;	
} 
