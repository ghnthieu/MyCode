Program mang_xo;
uses crt;
type mang1=array[1..100] of integer;
     mang2=array[1..10,1..10] of integer;
var n:byte;
    a:mang2;
procedure nhap(var a:mang2; var n:byte);
var i,j:byte;
begin
  write('Nhap cap mang: ');readln(n);
  for i:=1 to n do
    for j:=1 to n do
      begin
        write('a[',i,',',j,']=');readln(a[i,j]);
      end;
end;
procedure doi_cho(var a,b:integer);
var t:integer;
begin
  t:=a;
  a:=b;
  b:=t;
end;
procedure ma_xo(a:mang2; n:byte);
var i,j,k,t:byte;
    b:mang1;
    m:integer;
begin
  k:=0;
  for i:=1 to n do
    for j:=1 to n do
      begin
        inc(k);
        b[k]:=a[i,j];
      end;
  for i:=1 to k-1 do
    for j:=i+1 to k do
      if b[i]>b[j] then
        doi_cho(b[i],b[j]);
  for i:=1 to k do
    write(b[i],' ');
  writeln;
  i:=1;
  j:=1;
  k:=1;
  m:=n-1;
  while m>0 do
    begin
      for t:=1 to m do
        begin
          a[i,j]:=b[k];
          inc(j);
          inc(k);
        end;
      for t:=1 to m do
        begin
          a[i,j]:=b[k];
          inc(i);
          inc(k);
        end;
      for t:=1 to m do
        begin
          a[i,j]:=b[k];
          dec(j);
          inc(k);
        end;
      for t:=1 to m do
        begin
          a[i,j]:=b[k];
          dec(i);
          inc(k);
        end;
      m:=m-2;
      inc(i);
      inc(j);
    end;
  if m=0 then
    a[n div 2+1,n div 2+1]:=b[n*n];
  for i:=1 to n do
    begin
      for j:=1 to n do
        write(a[i,j],' ');
      writeln;
    end;
end;
Begin
  clrscr;
  nhap(a,n);
  ma_xo(a,n);
  readln
End.