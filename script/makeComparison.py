import re

import numpy as np
import uproot

# Load the data from the root file
data = uproot.open("data.root")["kin"].arrays(
    ["cosTheta_eta_hel_thrown", "phi_eta_hel_thrown", "Phi_thrown"], library="pd"
)

# Load the intensities extracted by print_amplitudes.cc
intensities = []
with open(".print_amplitudes.log") as file:
    for line in file:
        if "INTENSITY =" in line:
            line = re.sub(" +", " ", line.rstrip().lstrip())
            intensities.append(float(line.split()[2]))
intensities = np.array(intensities)

assert len(intensities) == len(data["cosTheta_eta_hel_thrown"])

# Rename dictionary keys
data["intensity"] = intensities
data = data.rename(
    {
        "cosTheta_eta_hel_thrown": "theta",
        "phi_eta_hel_thrown": "phi",
        "Phi_thrown": "Phi",
    },
    axis=1,
)

# Standardize the data to be angles in radians
DEGREE_TO_RADIAN = np.pi / 180.0
data["theta"] = np.arccos(data["theta"])
data["Phi"] = data["Phi"] * DEGREE_TO_RADIAN

data.to_csv("comparison.csv", index=False, sep=",")
