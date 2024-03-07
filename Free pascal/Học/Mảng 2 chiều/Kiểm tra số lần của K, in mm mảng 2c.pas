Program mang_2c;
uses crt;
type mang=array[1..10,1..10] of integer;
var a:mang;
    n,m:byte;
    k:integer;
procedure nhap(var a:mang; var n,m:byte; var k:integer);
var i,j:byte;
begin
  write('Nhap so hang: ');readln(m);
  write('Nhap so cot: ');readln(n);
  for i:=1 to m do
    for j:=1 to n do
      begin
        write('a[',i,',',j,']=');readln(a[i,j]);
      end;
  write('Nhap so K: ');readln(k);
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
procedure dem_sl(a:mang; n,m:byte; k:integer);
var i,j,dem:byte;
begin
  for i:=1 to m do
    for j:=1 to n do
      if a[i,j]=k then
        inc(dem);
  writeln(k,' xuat hien ',dem,' lan');
end;
procedure mm_cot(a:mang; n,m:byte);
var i,j:byte;
    max,min:integer;
begin
  j:=1;
  while (j<=n) do
    begin
      max:=a[1,j];
      min:=a[1,j];
      for i:=2 to m do
        begin
          if max<a[i,j] then
            max:=a[i,j];
          if min>a[i,j] then
            min:=a[i,j];
        end;
      writeln('Max cua cot ',j,' la: ',max);
      writeln('Min cua cot ',j,' la: ',min);
      inc(j);
    end;
end;
procedure mm_hang(a:mang; n,m:byte);
var i,j:byte;
    max,min:integer;
begin
  i:=1;
  while (i<=m) do
    begin
      max:=a[i,1];
      min:=a[i,1];
      for j:=2 to n do
        begin
          if max<a[i,j] then
            max:=a[i,j];
          if min>a[i,j] then
            min:=a[i,j];
        end;
      writeln('Max cua hang ',i,' la: ',max);
      writeln('Min cua hang ',i,' la: ',min);
      inc(i);
    end;
end;
Begin
  clrscr;
  nhap(a,n,m,k);
  in_ra(a,n,m);
  dem_sl(a,n,m,k);
  mm_cot(a,n,m);
  mm_hang(a,n,m);
  readln
End.