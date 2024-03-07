Program day_con;
uses crt;
type mang=array[1..100] of integer;
var a:mang;
    n:byte;
procedure nhap(var a:mang; var n:byte);
var i:byte;
begin
  write('Nhap do dai cua day: ');readln(n);
  for i:=1 to n do
    begin
      write('a[',i,']=');readln(a[i]);
    end;
end;
procedure in_ra(a:mang; n:byte);
var i:byte;
begin
  writeln('Mang vua nhap la: ');
  for i:=1 to n do
    write(a[i],' ');
  writeln;
end;
procedure day_con(a:mang; n:byte);
var i,dai,max,dau,csdau,dem:byte;
begin
  i:=0;
  dai:=1;
  max:=1;
  dau:=1;
  while i<=n do
    begin
      inc(i);
      if a[i]<=a[i+1] then
        inc(dai)
      else
        if dai>max then
          begin
            max:=dai;
            csdau:=dau;
            dai:=1;
            dau:=i+1;
          end
        else
          begin
            dai:=1;
            dau:=i+1;
          end;
    end;
  i:=csdau;
  dem:=0;
  while dem<max do
    begin
      inc(dem);
      write(a[i],' ');
      inc(i);
    end;
end;
Begin
  clrscr;
  nhap(a,n);
  in_ra(a,n);
  day_con(a,n);
  readln
End.