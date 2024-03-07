Program mang_2c;
uses crt;
type mang=array[1..10,1..10] of integer;
var a:mang;
    n,m:byte;
procedure nhap(var a:mang; var n,m:byte);
var i,j:byte;
begin
  write('Nhap so hang: ');readln(m);
  write('Nhap so cot: ');readln(n);
  for i:=1 to m do
    for j:=1 to n do
      begin
        write('a[',i,',',j,']=');readln(a[i,j]);
      end;
end;
procedure in_ra(a:mang; n,m:byte);
var i,j:byte;
begin
  for i:=1 to m do
    begin
      for j:=1 to n do
        write(a[i,j],' ');
      writeln;
    end;
end;
procedure th_mm(a:mang; n,m:byte);
var i,j:byte;
    tong,max,min:integer;
begin
  tong:=0;
  for j:=1 to n do
    tong:=tong+a[1,j];
  writeln('Tong hang 1 la: ',tong);
  max:=tong;
  min:=tong;
  for i:=2 to m do
    begin
      tong:=0;
      for j:=1 to n do
        tong:=tong+a[i,j];
      writeln('Tong hang ',i,' la: ',tong);
      if max<tong then
        max:=tong;
      if min>tong then
        min:=tong;
    end;
  writeln('Max tong hang la: ',max);
  writeln('Min tong hang la: ',min);
end;
procedure tc_mm(a:mang; n,m:byte);
var i,j:byte;
    tong,max,min:integer;
begin
  tong:=0;
  for i:=1 to m do
    tong:=tong+a[i,1];
  writeln('Tong cot 1 la: ',tong);
  max:=tong;
  min:=tong;
  for j:=2 to n do
    begin
      tong:=0;
      for i:=1 to m do
        tong:=tong+a[i,j];
      writeln('Tong cot ',j,' la: ',tong);
      if max<tong then
        max:=tong;
      if min>tong then
        min:=tong;
    end;
  writeln('Max tong cot la: ',max);
  write('Min tong cot la: ',min);
end;
Begin
  clrscr;
  nhap(a,n,m);
  in_ra(a,n,m);
  th_mm(a,n,m);
  tc_mm(a,n,m);
  readln
End.