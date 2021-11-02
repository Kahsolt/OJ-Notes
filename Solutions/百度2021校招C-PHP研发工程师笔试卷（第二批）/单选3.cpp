template <typename SrcT, typename DstT>
DstT cast(SrcT v)
{
return (DstT)(v);
}
int v = 0;
float i = cast<float>(v);