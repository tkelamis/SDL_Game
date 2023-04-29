

class MapObject
{
public:
	//1=hero,2=door,3=glob,4=mimic,5=chest(note:mimic look like chest)
	int type;
	//position on map grid
	int x, y;
	//when no active destroy this object
	bool active = true;
};