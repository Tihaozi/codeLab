# import os


# _path = "D:/CompoTool_project/nuke"

# asset_dir = _path + r'/assets'
# plan_dir = asset_dir + r'/S03_P17'

# plans = os.listdir(asset_dir)

# for plan in plans:
#     layers = ""
#     names = ""
#     persons = ""
#     aovs = ""
#     print plan
#     plan_dir = asset_dir + r'/' + plan
#     layers = os.listdir(plan_dir)

#     for layer in layers:
#         print "\t" + layer
#         name_dir = plan_dir + r'/' + layer
#         names = os.listdir(name_dir)

#         if layer == 'Characters' or layer == 'Environment' or layer == 'Props':
#             if layer == 'Characters':
#                 for name in names:
#                     print "\t\t" + name
#                     persons_dir = name_dir + r'/' + name
#                     persons = os.listdir(persons_dir)

#                     for person in persons:
#                         print "\t\t\t" + person
#                         aovs_dir = persons_dir + r'/' + person
#                         aovs = os.listdir(aovs_dir)
#                         print "len: ----------------" + str(len(aovs))
#                         for aov in aovs:
#                             print "\t\t\t\t" + aov
#             else:
#                 for name in names:
#                     print "\t\t" + name
#                     aovs_dir = name_dir + r'/' + name
#                     aovs = os.listdir(aovs_dir)

#                     for aov in aovs:
#                         print "\t\t\t" + aov
#         else:
#             for name in names:
#                 print "\t\t" + name

#     for name in names:
#         print "\t\t" + name


# ----------------------------------------------------------------------
# aov = 'Characters_direct_diffuse_0000.exr'
# print aov.split('_0000')[0]

# read_nodes_list = []
# entries = ['read01', 'read02', 'read03', 'read04']

# for e in entries:
#         read_nodes_list.append(e)


# print read_nodes_list

# for i in range(len(read_nodes_list)):
#     n1 = read_nodes_list.pop(0)
#     n2 = read_nodes_list.pop(0)
#     read_nodes_list.insert(0, n1 + n2)


# print read_nodes_list


nodes = ['Characters_Moavieh_beauty',
         'Characters_Moavieh_direct_diffuse',
         'Characters_Moavieh_direct_specular',
         'Characters_Moavieh_reflection',
         'Characters_Moavieh_refraction',
         'Characters_Moavieh_sheen',
         'Characters_Moavieh_specular',
         'Characters_Moavieh_sss']
new_nodes = []
for n in nodes:
    if n.find('beauty') != -1:
        continue
    else:
        new_nodes.append(n)

print new_nodes
print len(new_nodes)

for i in range(len(new_nodes)-1):
    print "merge2 created"


for i in range(len(new_nodes)):
    print new_nodes[i], ':', 'M'+str(i)    