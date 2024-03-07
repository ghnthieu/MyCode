Program bai1;
var a,b:integer;
function ucln_so(a,b:integer):integer;
var sodu:integer;
begin
  sodu:=a mod b;
  while sodu<>0 do
    begin
      a:=b;
      b:=sodu;
      sodu:=a mod b;
    end;
  ucln_so:=b;
end;
function daoso(n:integer):integer;
var t:integer;
begin
  t:=0;
  while n<>0 do
    begin
      t:=t*10+(n mod 10);
      n:=n div 10;
    end;
  daoso:=t;
end;
procedure xuly;
var dem,i:integer;
    fi,fo:text;
begin
  assign(fi,'bl1.inp');reset(fi);
  assign(fo,'bl1.out');rewrite(fo);
  read(fi,a,b);
  dem:=0;
  for i:=a to b do
    if ucln_so(i,daoso(i))=1 then
      inc(dem);
  write(fo,dem);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.
