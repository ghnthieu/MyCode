Program bai4_5;
uses crt;
var n1:longint;
    n2:ansistring;
procedure nhap(var n1:longint; var n2:ansistring);
begin
  write('Nhap so thap phan: ');readln(n1);
  write('Nhap day nhi phan: ');readln(n2);
end;
procedure in_n1(n1:longint);
var s,a:string;
begin
  s:='';
  while n1<>0 do
    begin
      str(n1 mod 2,a);
      s:=a+s;
      n1:=n1 div 2;
    end;
  writeln('Day so nhi phan la: ',s);
end;
function luythua(a,b:longint):longint;
var i:byte;
    kq:longint;
begin
  kq:=1;
  for i:=1 to b do
    kq:=kq*a;
  luythua:=kq;
end;
procedure in_n2(n2:ansistring);
var kq,t:longint;
    n,i:byte;
begin
  kq:=0;
  n:=length(n2);
  for i:=1 to n do
    begin
      val(n2[i],t);
      kq:=kq+t*luythua(2,n-i);
    end;
  write('Day so thap phan la: ',kq);
end;
Begin
  clrscr;
  nhap(n1,n2);
  in_n1(n1);
  in_n2(n2);
  readln
End.