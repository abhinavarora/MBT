#include "tinyxml.h"
#include "actorbuilder.h"
#include "messagebuilder.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    TiXmlDocument doc;
	if(!doc.LoadFile("C:/Users/Abhinav/Desktop/BTP/Model Based Testing/test.xml"))
	{
		cerr << doc.ErrorDesc() << endl;
		return 0;
	}
	TiXmlElement* root = doc.FirstChildElement();
	if(root == NULL)
	{
		cerr << "Failed to load file: No root element." << endl;
		doc.Clear();
		return 0;
	}
//TiXmlElement* elem = root->FirstChildElement()->NextSiblingElement();
//cout<<elem->Attribute("att");
vector<Actor> list;
vector<Message> mlist;
ActorBuilder acb;
acb.build(list,root);
//list=root->GetElementsByTagName("message",list);
for(int i=0;i<list.size();i++)
    cout<<list[i].toString()<<endl<<endl;
MessageBuilder mb;
mb.build(list,mlist,root);
cout<<mlist.size();
for(int i=0;i<mlist.size();i++,cout<<endl)
    mlist[i].display();
//getchar();
return 0;
}
