

struct node{
    ptr iz;
    ptr der;
    int val;	//O.o
    int numero;
    node(){
        numero=-1;
        val=0;
    }
};
node nodos[tam];int cnodos=0;
node NUL;
ptr getnode()
{
    nodos[cnodos].iz=nodos[cnodos].der=&NUL;
    //if (cnodos>=tam)
         //tle(); no 
    return &nodos[cnodos++];
}
void clr(){
    NUL.iz=NUL.der=&NUL;
}

void insertar(ptr nuevo,ptr antnodo,int iz,int der,int pos,int numero)
{
    if (iz==der)
    {

        (*nuevo).val=(*antnodo).val+1;
        (*nuevo).numero=numero;
        return;
    }
    int mid=(iz+der)/2;
    if (pos<=mid)
    {
        (*nuevo).der=(*antnodo).der;
        (*nuevo).iz=getnode();
        insertar((*nuevo).iz,(*antnodo).iz,iz,mid,pos,numero);
    }
    else
    {
        (*nuevo).iz=(*antnodo).iz;
        (*nuevo).der=getnode();
        insertar((*nuevo).der,(*antnodo).der,mid+1,der,pos,numero);
    }
    (*nuevo).val=(*(*nuevo).iz).val+(*(*nuevo).der).val;
}

int query(ptr nodoa,ptr nodob,ptr resta1,ptr resta2,int kth,int iz,int der)
{
    if (iz==der)
    {
	return iz;// numero
    }
    int valiz=(*(*nodoa).iz).val+(*(*nodob).iz).val-(*(*resta1).iz).val-(*(*resta2).iz).val;
    int mid=(iz+der)/2;
    if (kth>valiz)
    {
        query((*nodoa).der,(*nodob).der,(*resta1).der,(*resta2).der,kth-valiz,mid+1,der);//kth-valiz ***
    }
    else
    {
        query((*nodoa).iz,(*nodob).iz,(*resta1).iz,(*resta2).iz,kth,iz,mid);
    }
}
