#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *cyber_incident_platforms[] = {
    "pastebin.com",
    "securityforums.com",
    "twitter.com/cybersecurity",
    "github.com/cyber-reports",
    "reddit.com/r/cybersecurity",
    "darkwebreports.onion",
    NULL
};

typedef struct {
    char platform[256];
    char title[1024];
    char description[4096];
    time_t timestamp;
    char sector[256];
    char apt[256];
    char strategic_issue[256];
} CyberIncident;

void simulate_web_crawl(const char *platform, CyberIncident *incident) {
    strcpy(incident->platform, platform);
    snprintf(incident->title, sizeof(incident->title), "Simulated Cyber Incident from %s", platform);
    snprintf(incident->description, sizeof(incident->description), "This is a simulated description of a cyber incident reported on %s.", platform);
    incident->timestamp = time(NULL);

    const char *sectors[] = {"Banking", "Telecom", "Energy", "Healthcare"};
    const char *apts[] = {"APT-1", "APT-28", "Unknown"};
    const char *strategic_issues[] = {"Data Breach", "Ransomware", "DDoS"};

    strcpy(incident->sector, sectors[rand() % (sizeof(sectors) / sizeof(sectors[0]))]);
    strcpy(incident->apt, apts[rand() % (sizeof(apts) / sizeof(apts[0]))]);
    strcpy(incident->strategic_issue, strategic_issues[rand() % (sizeof(strategic_issues) / sizeof(strategic_issues[0]))]);
}

#define MAX_INCIDENTS 1000
CyberIncident incidents[MAX_INCIDENTS];
int incident_count = 0;

void store_incident(const CyberIncident *incident) {
    if (incident_count < MAX_INCIDENTS) {
        incidents[incident_count++] = *incident;
    } else {
        printf("Database full. Cannot store more incidents.\n");
    }
}

void generate_insights() {
    printf("\nCyber Incident Insights:\n");
    printf("Total incidents: %d\n", incident_count);

    int banking_count = 0, telecom_count = 0, energy_count = 0, healthcare_count = 0;
    for (int i = 0; i < incident_count; i++) {
        if (strcmp(incidents[i].sector, "Banking") == 0) banking_count++;
        else if (strcmp(incidents[i].sector, "Telecom") == 0) telecom_count++;
        else if (strcmp(incidents[i].sector, "Energy") == 0) energy_count++;
        else if (strcmp(incidents[i].sector, "Healthcare") == 0) healthcare_count++;
    }
    printf("Banking incidents: %d\n", banking_count);
    printf("Telecom incidents: %d\n", telecom_count);
    printf("Energy incidents: %d\n", energy_count);
    printf("Healthcare incidents: %d\n", healthcare_count);
}

int main() {
    srand(time(NULL));

    for (int i = 0; cyber_incident_platforms[i] != NULL; i++) {
        CyberIncident incident;
        simulate_web_crawl(cyber_incident_platforms[i], &incident);
        store_incident(&incident);
    }

    generate_insights();

    return 0;
}