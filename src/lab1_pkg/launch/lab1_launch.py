from launch import LaunchDescription
from launch_ros.actions import Node
def generate_launch_description():
    ld = LaunchDescription()

    talkerNode = Node(
        package='lab1_pkg',
        executable='talker_og.py',
        parameters=[
            {'v': 5},
            {'d': 3}
        ]
    )

    relayNode = Node(
        package='lab1_pkg',
        executable='relay'
    )

    ld.add_action(talkerNode)
    ld.add_action(relayNode)

    return ld
    
