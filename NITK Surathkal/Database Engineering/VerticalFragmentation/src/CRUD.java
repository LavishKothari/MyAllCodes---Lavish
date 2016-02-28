
public class CRUD {
	boolean c,r,u,d;
	int manipulateCount,readCount;
	CRUD(boolean c,boolean r,boolean u,boolean d)
	{
		this.c=c;
		this.r=r;
		this.u=u;
		this.d=d;
	}
	CRUD(){}
	public String toString(){
		String res="";
		boolean flag=false;
		if(c){ res+="C"; flag=true; manipulateCount++; }
		if(r){ res+="R"; flag=true; readCount++; }
		if(u){ res+="U"; flag=true; manipulateCount++; }
		if(d){ res+="D"; flag=true; manipulateCount++; }
		if(!flag) res+="N";
		res+=",";
		return res;
	}

}
