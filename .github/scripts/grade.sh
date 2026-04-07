#!/bin/bash

# 1. Source the ROS 2 environment
source /opt/ros/jazzy/setup.bash

# 2. Source the local workspace (if it was built)
if [ -f install/setup.bash ]; then
  source install/setup.bash
else
  echo "❌ Error: install/setup.bash not found. Did the build fail?"
  exit 1
fi

# 3. Run the node with a timeout and capture output
echo "Running node..."
timeout 5s ros2 run entri_ros2_basics_cpp hello_node > output.log 2>&1 || true

# 4. Check results
if grep -q "Hello, World!" output.log; then
  echo "✅ Found 'Hello, World!'"
  exit 0
else
  echo "❌ Could not find 'Hello, World!' in output:"
  cat output.log
  exit 1
fi
