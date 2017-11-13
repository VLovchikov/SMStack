// TSMStack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

class TStack
{
	int *mem;
	int n;
	int ind;
public:
	TStack(int *_mem,int _n):mem(_mem),n(_n),ind(-1){}
	bool isFull()
	{
		return ind >= n - 1;
	}
	bool isEmpty()
	{
		return ind < 0;
	}
	void push(int val)
	{
		if (isFull()) throw - 1;
		ind++;
		mem[ind] = val;
	}
	int count()
	{
		return ind + 1;
	}
	int size()
	{
		return *mem;
	}
};

class TSMStack
{
	int *mem;
	int n;
	TStack **st;
	int st_cnt;
public:
	TSMStack(int n, int k)
	{
		int p = 0;
		mem = new int[n];
		this->n = n;
		st_cnt = k;
		st = new TStack *[k];
		for (int i = 0; i < k; i++)
		{
			int s = n / k;
			if (i < n / k) s++;
			st[i] = new TStack(mem + p, s);
			p += s;
		}
	}
	bool isFull()
	{
		bool f = true;
		for (int i = 0; i < st_cnt; i++)
		{
			f = f&&st[i]->isFull();
		}
		return f;
	}
	bool isEmpty(int i)
	{
		return st[i]->isEmpty();
	}
	void push(int i, int val)
	{
		try
		{
			st[i]->push(val);
		}
		catch (...)
		{
			resize.st[i];
			st[i]->push(val);
		}
	}
	void resize *st (int ii)
	{
		int *cnt;
		cnt = new int[st_cnt];
		int s = 0;
		for (int i = 0; i < st_cnt; i++)
		{
			cnt[i] = st[i]->count();
			s += cnt[i];
		}
		s++;
		cnt[ii]++;
		if (s > n) throw - 2;
		int sm = n - s;
		int *new_cnt;
		new_cnt = new int[st_cnt];
		for (int i = 0; i < st_cnt; i++)
		{
			new_cnt[i] = cnt[i] + sm / st_cnt;
			if (i < sm%st_cnt) new_cnt[i]++;
		}
		int p = st[0]->count();
		int k = st[0]->size();
		for (int i = 0; i < st_cnt; i++)
		{
			for (int j = 0; j < st[i]->count(); j++)
			{
				mem[p] = mem[k + j];
				p++;
			}
			k = +st[i]->size();
		}
		int *pp = new int[st_cnt + 1];
		pp[0] = 0;
		for (int i = 1; i < st_cnt; i++)
		{
			pp[i] = new_cnt[i - 1] + pp[i - 1];	
		}
		for (int i = st_cnt; i > 0; i--)
		{
			for (int j = st[i]->count()-1; j >= 0; j--)
			{
				p--;
				mem[j + pp[i]] = mem[p];
			}
		}
		cnt[ii]--;
		for (int i = 0; i < st_cnt; i++)
		{
			delete st[i];
			st[i] = new TStack(mem + pp[i], cnt[i]);
		}
		delete[] cnt;
		delete[] new_cnt;
		delete[] pp;
	}
};

int main()
{
    return 0;
}

