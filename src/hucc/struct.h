int find_tag (char *sname);
int define_struct (char *sname, int storage, int is_struct);
void add_member (char *sname, char identity, char type, int offset, int storage_class, int otag, int ptr_order, int funcptr_type, int funcptr_order, int arg_count);
